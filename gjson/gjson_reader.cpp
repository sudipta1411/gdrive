#include <cstdlib>
#include "gjson/gjson_reader.h"

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

    GJsonReader :: GJsonReader(std::string& _doc)
    {
        doc = _doc;
        begin = doc.c_str();
        end = begin + doc.length();
        current = begin;
        root = nullptr;
        _stack = std::stack<char>();
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
        return *current++;
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
        skipWhiteSpace();
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
            if(isWhiteSpace(ch) || ch == ',')
                break;
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
            if(isWhiteSpace(ch) || ch == ',')
                break;
            
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

    /*bool readArrayToken(GJsonReader :: Token *token)
    {
        return true;
    }*/
END_GJSON_NAMESPACE
