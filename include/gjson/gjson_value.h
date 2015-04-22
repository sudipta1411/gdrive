#ifndef __GJSONVALUE_h__
#define __GJSONVALUE_h__

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

    /*converts base calss value to a proper derived class value,
	 * using type information*/
	template<typename T>
	T gjson_cast(GenericValue *value)
	{
		if(!value)
			return 0;
		return dynamic_cast<T>(value);
	}

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
			GJsonValue(T _value,value_type_t _type = null_value) :
                GenericValue(_type),value(_value)/*,type(_type)*/ {}
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

	class GJsonLong : public GJsonValue<long>
	{
		public :
			GJsonLong(long _value) : GJsonValue(_value,long_value) {}
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
	class GJsonArray : public GenericValue
	{
		typedef GenericValue* ptr_to_gen;
		private :
			std::vector<GenericValue*> *array;
		public :
			GJsonArray();
			GJsonArray(const GJsonArray &j_array);
			~GJsonArray();
			bool add(const ptr_to_gen& value);
			GenericValue* get(int pos);
            unsigned size() const;
			std::string stringify() const;
	};

    class GJsonMap : public GenericValue
    {
        private:
            std::string key;
            std::vector<GenericValue*> children;
        public :
            GJsonMap(std::string key="JSON_OBJECT");
            ~GJsonMap();
            void addChild(GenericValue* value);
            void setKey(std::string& key);
            std::string getKey() const;
            unsigned size() const;
            GenericValue* find(const std::string& key);
            GenericValue* operator[](const std::string& key);
			std::string stringify() const;

    };

    bool getValue(GenericValue* gv,long& result);
    bool getValue(GenericValue* gv,double& result);
    bool getValue(GenericValue* gv,std::string& result);
    bool getValue(GenericValue* gv,bool& result);

END_GJSON_NAMESPACE

#endif /*__GJSONVALUE_h__*/
