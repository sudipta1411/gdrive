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

    char GJsonReader :: getNextChar()
    {
        if(current == end)
            return 0;
        return *current++;
    }

    GJsonReader::Token* GJsonReader :: readNextToken()
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
    }

    bool readArrayToken(GJsonReader :: Token *token)
    {
        return true;
    }
END_GJSON_NAMESPACE
