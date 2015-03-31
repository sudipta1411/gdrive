#include "gjson/gjson_reader.h"

BEGIN_GJSON_NAMESPACE
    GJsonReader :: GJsonReader()
    {
        begin = end = NULL;
        current = begin;
        root = NULL;
        doc = std::string();
    }

    GJsonReader :: GJsonReader(std::string& _doc)
    {
        doc = doc;

    }
END_GJSON_NAMESPACE
