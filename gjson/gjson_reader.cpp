#include <cstdlib>
#include "gjson/gjson_reader.h"
#include <iostream>
using namespace std;

#define IS_HEX_CHAR(c) (((c)>='A' && (c)<='F') || ((c)>='a' && (c)<='f'))

BEGIN_GJSON_NAMESPACE
    GJsonReader :: GJsonReader()
    {
        begin = end = nullptr;
        current = begin;
        root = nullptr;
        doc = std::string();
        _stack = std::stack<char>();
    }

    GJsonReader :: GJsonReader(const std::string& _doc)
    {
        doc = _doc;
        begin = doc.c_str();
        end = begin + doc.length();
        current = begin;
        root = nullptr;
        _stack = std::stack<char>();
    }

    GJsonReader :: ~GJsonReader()
    {
       begin = end = current = nullptr; 
       delete root;
    }
    
    bool GJsonReader :: parse()
    {
        if(doc.length() == 0)
            return false;
        char ch = getNextChar();
        if(ch == OBJECT_BEGIN) 
        {
            _stack.push(ch);
            root = readObject();
        }
        return root != nullptr;
    }

    bool GJsonReader :: parse(const std::string& _doc)
    {
        doc = _doc;
        begin = doc.c_str();
        end = begin + doc.length();
        current = begin;
        root = nullptr;
        _stack = std::stack<char>();
        return parse();
    }

    bool GJsonReader :: ok() const
    {
       return _stack.empty(); 
    }

    GenericValue* GJsonReader :: getValue(const std::string& key) const
    {
        if(root != nullptr)
            return root->find(key);
        return nullptr;
    }

    void GJsonReader :: skipWhiteSpace()
    {
        char ch;
        while(current != end)
        {
            ch = *current;
            if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
                current++;
            else 
                break;
        }
    }

    bool inline GJsonReader :: isWhiteSpace(char ch)
    {
        return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r');
    }

    char GJsonReader :: getNextChar()
    {
        if(current == end)
            return 0;
        //cout << *current << endl;
        return *current++;
    }

    bool inline GJsonReader :: isLastElem(char c)
    {
        return ((c == ARRAY_END && _stack.top() == ARRAY_BEGIN)
                || (c == OBJECT_END && _stack.top() == OBJECT_BEGIN));
    }

    bool GJsonReader :: isEqualToChar(char c)
    {
        skipWhiteSpace();
        char ch = getNextChar();
        return ch==c;
    }

    /*GJsonReader::Token* GJsonReader :: readNextToken()
    {
        Token* token = new Token();
        skipWhiteSpace();
        token->begin = current;
        char ch = getNextChar();
        bool ok = true;
        switch(ch)
        {
            case ARRAY_BEGIN:
                token->type = token_array;
                _stack.push(ch);
                ok = readArrayToken(token);
                break;

        }
        return token;
    }*/

    GJsonString* GJsonReader :: readString()
    {
        std::string s;
        char ch;
        GJsonString* j_str = nullptr;
        //skipWhiteSpace();
        while(current != end)
        {
            ch = getNextChar();
            if(ch == '\\')
            {
                s.append(1,ch);
                ch = getNextChar();
                s.append(1,ch);
                continue;
            }
            if(ch == STRING_END || ch == STRING_END_1)
            {
                if(ch == _stack.top())
                {
                    _stack.pop();
                    break;
                }
                else /*Error Handling*/
                    return nullptr;
            }
            s.append(1,ch);
        }
        j_str = new GJsonString(s);
        return j_str;
    }

    GJsonLong* GJsonReader :: readLong()
    {
        long sum = 0;
        long val = 0;
        int base = 10;
        GJsonLong* j_long = nullptr;

        char ch = getNextChar();
        bool isNeg = (ch == '-');
        if(!isNeg)
        {
            if(ch != '+')
                --current;
        }
        
        //HEX value
        if(*current=='0' && (*(current+1)=='x'||*(current+1)=='X'))
        {
            base = 16;
            current += 2;
        }
        while(current != end)
        {
            ch = getNextChar();
            if(isWhiteSpace(ch) || ch == SEPERATOR || isLastElem(ch))
            {
                current--;
                break;
            }
            /*if(std::atoi(&ch) >= base)
                break;*/

            sum = val * base;
            if(/*ch >= '0' && ch <= '9'*/std::isdigit(ch))
                val = (sum + std::atoi(&ch));
            else if(base == 16 /*&& IS_HEX_CHAR(ch)*/)
            {
                if(IS_HEX_CHAR(ch))
                {
                    val = sum + [] (char c){ return std::isupper(c) ? 
                            (c - 'A' + 10) : 
                            (c - 'a' + 10); }
                            (ch);
                }
                else
                {
                    return j_long; //ERROR
                }
            }
        }
        if(isNeg) val *= -1;
        j_long = new GJsonLong(val);
        return j_long;
    }

    GJsonReal* GJsonReader :: readReal()
    {
        double val = 0.0;
        double sum = 0.0;
        int base = 10;
        int dec_num = 0;
        GJsonReal* j_real = nullptr;
        char ch = getNextChar();
        bool isNeg = (ch == '-');
        bool isDec = false;
        if(!isNeg)
        {
            if(ch != '+')
                --current;
        }

        while(current != end)
        {
            ch = getNextChar();
            if(isWhiteSpace(ch) || ch == SEPERATOR || isLastElem(ch))
            {   
                current--;
                break;
            }
            
            if(ch=='.' && !isDec)
            {
                isDec = true;
                ch = getNextChar();
            }
            if(!std::isdigit(ch))
            {
                return j_real; //ERROR
            }
            if(isDec)
            {
                dec_num++;
                val += [=](char c,int dec) { double ret_val = std::atoi(&c);
                        while(dec--) ret_val /= base;
                        return ret_val;
                    }(ch,dec_num);
            }
            else
            {
                sum = val * base;
                if(/*ch >= '0' && ch <= '9'*/std::isdigit(ch))
                    val = (sum + std::atoi(&ch));
            
            }
        }
        if(isNeg) val *= -1;
        j_real = new GJsonReal(val);
        return j_real;
    }

    /*this method will get called when 
     either 't' or 'f' has already been read*/
    GJsonBool* GJsonReader :: readBool(char cur)
    {
        GJsonBool* j_bool = nullptr;
        bool boolean;
        char ch;
        while(current != end)
        {
            ch = getNextChar();
            if(isWhiteSpace(ch) || ch == SEPERATOR || isLastElem(ch))
                break;

            if(cur == 't')
            {
                if(ch == 'r' && *current == 'u' && *(current+1) == 'e')
                {
                    boolean = true;
                    current += 2;
                    break;
                }
                else if(ch == 'a' && *current == 'l' && *(current+1) == 's'
                        && *(current +2) == 'e')
                {
                    boolean = false;
                    current += 3;
                    break;
                }
                else
                {
                    return j_bool; //ERROR
                }
            }
        }
        j_bool = new GJsonBool(boolean);
        return j_bool;
    }

    GJsonArray* GJsonReader :: readArray()
    {
        GJsonArray* j_array = new GJsonArray();
        char ch;
        while(current != end)
        {
            skipWhiteSpace();
            ch = getNextChar();
            //cout << "readArray : " << ch <<endl;
            if(ch == ARRAY_END)
            {
                if(ARRAY_BEGIN == _stack.top())
                {
                    _stack.pop();
                    break;
                }
                else
                {
                    //ERROR
                    return nullptr;
                }
            }
            /*XXX TO-DO :nullptr return value is to be checked for errors*/
            if(std::isdigit(ch))//Either integer or float value
            {
                --current;
                GJsonLong *j_long = readLong();
                //cout << "value : "<<j_long->getValue() << "current : " << *current<<endl;
                j_array->add(j_long);
            }
            else if(ch == STRING_BEGIN || ch == STRING_BEGIN_1)
            {
                _stack.push(ch);
                GJsonString* j_string = readString();
                j_array->add(j_string);
            }
            else if(ch == 't' || ch == 'f')
            {
                GJsonBool* j_bool = readBool(ch);
                j_array->add(j_bool);
            }
            else if(ch == ARRAY_BEGIN)
            {
                _stack.push(ch);
                GJsonArray* nested = readArray();
                j_array->add(nested);
            }
            else if(ch == OBJECT_BEGIN)
            {
                _stack.push(ch);
                GJsonMap* j_map = readObject();
                j_array->add(j_map);
            }
        }
        return j_array;
    }

    GJsonMap* GJsonReader :: readMap()
    {
        char ch;
        GJsonMap* j_map = new GJsonMap();
        bool has_read_sep = false;
        //cout << "Caling readMap" << endl;
        while(current != end)
        {
            skipWhiteSpace();
            ch = getNextChar();
            //cout << "readMap : " << ch << endl;
            if(ch == SEPERATOR)
                break;
            if(ch == OBJECT_END && _stack.top() == OBJECT_BEGIN)
            {
                --current;
                break;
            }
            has_read_sep = (!has_read_sep)?(ch==KEY_VALUE_SEP):true;
            //cout << "has_read_sep : " << has_read_sep << endl;
            if(ch == STRING_BEGIN || ch == STRING_BEGIN_1)
            {
                _stack.push(ch);
                GJsonString* j_str = readString();
                if(has_read_sep == false) 
                {
                    //has_read_sep = true;
                    //cout<<"Key : "<<j_str->getValue()<<endl;
                    std::string key = j_str->getValue();
                    j_map->setKey(key);
                }
                else 
                {
                    //cout<<"Value : "<<j_str->getValue()<<endl;
                    j_map->addChild(j_str);
                    //has_read_sep = !isEqualToChar(SEPERATOR);
                    
                }
            }
            else if(std::isdigit(ch))
            {
                --current;
                GJsonLong *j_long = readLong();
                //cout << "Long value : " << j_long->getValue()<<endl;
                j_map->addChild(j_long);
            }
            else if(ch == 't' || ch == 'f')
            {
                GJsonBool* j_bool = readBool(ch);
                j_map->addChild(j_bool);
            }
            else if(ch == ARRAY_BEGIN)
            {
                _stack.push(ch);
                GJsonArray* j_array = readArray();
                j_map->addChild(j_array);
            }
            else if(ch == OBJECT_BEGIN)
            {
                GJsonMap* nested = readObject();
                j_map->addChild(nested);
            }
            
        }
        return j_map;
    }

    GJsonMap* GJsonReader :: readObject()
    {
        char ch;
        GJsonMap* j_map = new GJsonMap();
        while(current != end)
        {
            skipWhiteSpace();
            ch = getNextChar();
            //cout << "readObject : " << ch << endl;
            if(ch == OBJECT_END)
            {
                if(OBJECT_BEGIN == _stack.top())
                {
                    _stack.pop();
                    break;
                }
                else
                {
                    //ERROR
                    return nullptr;
                }
            }
            current--;
            j_map->addChild(readMap());
        }
        return j_map;
    }
END_GJSON_NAMESPACE
