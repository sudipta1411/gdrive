#ifndef __GJSONVALUE_h__
#define __GJSONVALUE_h__

//#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "gjson/gjson_type.h"
#include "util/HashMap.h"

BEGIN_GJSON_NAMESPACE
	/*Generic value*/
	class GenericValue
	{
		private :
			value_type_t type;
		public :
            GenericValue() : type(null_value) {}
			GenericValue(value_type_t _type) : type(_type) {}
			virtual ~GenericValue() {}
			virtual std::string stringify() const
            {
                return std::string();
            }
			value_type_t getType() const
			{
				return this->type;
			}
	};

	template<typename T>
	class GJsonValue : public GenericValue
	{
		protected :
			T value;
		private :
			/*Copy constructor disabled*/
			GJsonValue(const GJsonValue<T> &_value);
			/*value_type_t type;*/
		public :
			GJsonValue(T _value,value_type_t _type = null_value) : GenericValue(_type),value(_value)/*,type(_type)*/ {}
			~GJsonValue()
			{
				//std::cout << "Deleting " << getType() << std::endl;
			}
			virtual T getValue() const { return value; }
	};

	class GJsonInt : public GJsonValue<int>
	{
		public :
			GJsonInt(int _value) : GJsonValue(_value,int_value) {}
			std::string stringify() const
			{
				return std::string();
			}
	};

	class GJsonReal : public GJsonValue<double>
	{
		public :
			GJsonReal(double _value) : GJsonValue(_value,real_value) {}
			std::string stringify() const
			{
				return std::string();
			}
	};

	class GJsonString : public GJsonValue<std::string>
	{
		public:
			GJsonString(std::string &_value) : GJsonValue(_value,string_value) {}
			std::string stringify() const
			{
				return value;
			}
	};

	class GJsonBool : public GJsonValue<bool>
	{
		public :
			GJsonBool(bool _value) : GJsonValue(_value,bool_value) {}
			std::string stringify() const
			{
				return std::string();
			}
	};

	/*An array can contain any type of value
	 * eg [1,2,"x",{"y":1234}]*/
	class GJsonArray : GenericValue
	{
		typedef GenericValue* ptr_to_gen;
		private :
			std::vector<GenericValue*> *array;
		public :
			GJsonArray():GenericValue(array_value)
			{
				array = new std::vector<GenericValue*>();
			}
			GJsonArray(const GJsonArray &j_array) : GenericValue(array_value)
			{
				const std::vector<GenericValue*> *v = j_array.getArray();
				array = new std::vector<GenericValue*>(*v);
			}
			~GJsonArray()
			{
				for(std::vector<GenericValue*>::iterator first = array->begin();
								first != array->end();first++)
				{
					delete *first;
				}
				delete array;
			}
			std::vector<GenericValue*> *getArray() const
			{
				return array;
			}

			bool add(const ptr_to_gen& value)
			{
				array->push_back(value);
				return true;
			}

			GenericValue* get(int pos)
			{
				if(pos<0 || (unsigned)pos>=array->size())
					return (GenericValue*)0;
				return array->at(pos);
			}

			std::string stringify() const
			{
				return std::string();
			}
	};

	class GJsonMap : public GenericValue
	{
		private :
			//std::map<GenericValue*,GenericValue*> *jsonMap;
            HashMap<std::string,GenericValue*> *jsonMap;
		public:
		   	GJsonMap() : GenericValue(object_value)
			{
				jsonMap = new HashMap<std::string,GenericValue*>();
			}
            ~GJsonMap()
            {
                std::vector<std::string> keys = jsonMap->keys();
                for(unsigned i=0;i<keys.size();i++)
                {
                    GenericValue *value = jsonMap->get(keys[i]);
                    delete value;
                }
                delete jsonMap;
            }
            void put(const std::string& key, GenericValue* value)
            {
                jsonMap->put(key,value);
            }
            void put(const char* key,GenericValue* value)
            {
                const std::string k(key);
                put(k,value);
            }
            GenericValue* get(const std::string& key) const
            {
                return jsonMap->get(key);
            }
            GenericValue* get(const char* key) const
            {
                std::string k(key);
                return get(k);
            }
            std::string stringify() const
            {
                return std::string();
            }
	};

	/*converts base calss value to a proper derived class value,
	 * using type information*/
	template<typename T>
	T gjson_cast(GenericValue *value)
	{
		if(!value)
			return 0;
		return dynamic_cast<T>(value);
	}

END_GJSON_NAMESPACE

#endif /*__GJSONVALUE_h__*/
