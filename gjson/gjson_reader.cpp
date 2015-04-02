#include "gjson/gjson_reader.h"

BEGIN_GJSON_NAMESPACE
    GJsonReader :: GJsonReader()
    {
        begin = end = NULL;
        current = begin;
        //root = NULL;
        doc = std::string();
    }

    GJsonReader :: GJsonReader(std::string& _doc)
    {
        doc = _doc;
        begin = doc.c_str();
        end = begin + doc.length();
        current = begin;
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
END_GJSON_NAMESPACE
