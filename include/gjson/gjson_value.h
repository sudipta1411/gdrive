#ifndef __GJSONVALUE_h__
#define __GJSONVALUE_h__

#include <string>
#include "gjson/gjson_type.h"

BEGIN_GJSON_NAMESPACE
	/*Generic value*/
	template<typename T>
	class GJsonValue 
	{
		protected :
			T value;
		private :
			value_type_t type;
		public :
			GJsonValue(T _value,value_type_t _type = null_value) : value(_value),type(_type) {}
			virtual std::string stringify() const = 0;
			T getValue() const { return value; } 
			value_type_t getType() const
			{
				return this->type;
			}
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
			GJsonString(std::string _value) : GJsonValue(_value,string_value) {}
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
END_GJSON_NAMESPACE

#endif /*__GJSONVALUE_h__*/
