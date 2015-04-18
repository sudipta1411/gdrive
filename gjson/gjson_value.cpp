#include "gjson/gjson_value.h"

BEGIN_GJSON_NAMESPACE
    bool getValue(GenericValue* gv,long& result)
    {
        if(gv == nullptr || gv->getType() != long_value)
            return false;
        GJsonLong* j_long = gjson_cast<GJsonLong*>(gv);
        if(j_long == nullptr)
            return false;
        result = j_long->getValue();
        return true;
    }

    bool getValue(GenericValue* gv,double& result)
    {
        if(gv == nullptr || gv->getType() != real_value)
            return false;
        GJsonReal* j_real = gjson_cast<GJsonReal*>(gv);
        if(j_real == nullptr)
            return false;
        result = j_real->getValue();
        return true;
    }

    bool getValue(GenericValue* gv,std::string& result)
    {
        if(gv == nullptr || gv->getType() != string_value)
            return false;
        GJsonString* j_str = gjson_cast<GJsonString*>(gv);
        if(j_str == nullptr)
            return false;
        result = j_str->getValue();
        return true;
    }

    bool getValue(GenericValue* gv,bool& result)
    {
        if(gv == nullptr || gv->getType() != bool_value)
            return false;
        GJsonBool* j_bool = gjson_cast<GJsonBool*>(gv);
        if(j_bool == nullptr)
            return false;
        result = j_bool->getValue();
        return true;
    }
END_GJSON_NAMESPACE
