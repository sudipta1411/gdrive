#include <cstdlib>
#include "gjson/gjson_reader.h"

BEGIN_GJSON_NAMESPACE
    GJsonReader :: GJsonReader()
    {
        begin = end = NULL;
        current = begin;
        root = NULL;
        doc = std::string();
        _stack = std::stack<char>();
    }

    GJsonReader :: GJsonReader(std::string& _doc)
    {
        doc = _doc;
        begin = doc.c_str();
        end = begin + doc.length();
        current = begin;
        root = NULL;
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
        GJsonString* j_str = NULL;
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
                    return NULL;
            }
            s.append(1,ch);
        }
        j_str = new GJsonString(s);
        return j_str;
    }

    GJsonInt* GJsonReader :: readInt()
    {
        int sum = 0;
        int val = 0;
        const int base = 10;
        GJsonInt* j_int = NULL;

        char ch = getNextChar();
        bool isNeg = (ch == '-');
        if(!isNeg) --current;
        while(current != end)
        {
            ch = getNextChar();
            if(isWhiteSpace(ch) || ch == ',')
                break;
            sum = val*base;
            if(ch >= '0' && ch <= '9')
                val = (sum + std::atoi(&ch));
        }
        if(isNeg) val *= -1;
        j_int = new GJsonInt(val);
        return j_int;
    }

    /*bool readArrayToken(GJsonReader :: Token *token)
    {
        return true;
    }*/
END_GJSON_NAMESPACE
