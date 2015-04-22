#include "gjson/gjson_value.h"

BEGIN_GJSON_NAMESPACE
    GJsonArray :: GJsonArray():GenericValue(array_value)
    {
        array = new std::vector<GenericValue*>();
    }

    GJsonArray :: GJsonArray(const GJsonArray& j_array) 
        : GenericValue(array_value)
    {
	    const std::vector<GenericValue*> *v = j_array.array;
		array = new std::vector<GenericValue*>(*v);
    }

    GJsonArray :: ~GJsonArray()
    {
	    for(std::vector<GenericValue*>::iterator first = array->begin();
		        first != array->end();first++)
		{
			delete *first;
		}
		delete array;
	}

    bool GJsonArray :: add(const ptr_to_gen& value)
    {
        array->push_back(value);
        return true; 
    }

    GenericValue* GJsonArray :: get(int pos)
    {
        if(pos<0 || (unsigned)pos>=array->size())
            return nullptr;
        return array->at(pos);
    }

    unsigned inline GJsonArray :: size() const { return array->size(); }

    std::string GJsonArray :: stringify() const
    {
        return std::string();
    }

    GJsonMap :: GJsonMap(std::string key) : 
            GenericValue(object_value)
    {
        this->key = key;
        children = std::vector<GenericValue*>();
    }
    
    GJsonMap :: ~GJsonMap()
    {
        for(auto ptr : children)
        {
            delete ptr;
        }
    }

    void GJsonMap :: addChild(GenericValue* value)
    {
        children.push_back(value);
    }

    void GJsonMap :: setKey(std::string& key)
    {
        this->key = key;
    }

    std::string inline GJsonMap :: getKey() const { return this->key; }

    unsigned inline GJsonMap :: size() const { return children.size(); }

    GenericValue* GJsonMap :: find(const std::string& key)
    {
        for(auto gv : children)
        {
            if(gv->getType() == object_value)
            {
                GJsonMap* tmp = gjson_cast<GJsonMap*>(gv);
                if(tmp->getKey() == key)
                {
                    if(tmp->size()==1u)
                        return tmp->children.at(0);
                    return gv;
                }
            }
        }
        return nullptr;
    }

    GenericValue* GJsonMap :: operator[](const std::string& key)
    {
        return find(key);
    }
    
    std::string GJsonMap :: stringify() const
    {
        return std::string();
    }

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
