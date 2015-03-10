#ifndef __GJSONVALUE_h__
#define __GJSONVALUE_h__

#include <iostream>
#include "gjson/gjson_type.h"

BEGIN_GJSON_NAMESPACE
	class GJsonValue 
	{
		protected :
			value_type_t type;
		public :
			GJsonValue(value_type_t _type = null_value) : type(_type) {}
			virtual std::string stringify() = 0;
			value_type_t getType() const
			{
				return this->type;
			}
	};

	class GJsonInt : public GJsonValue 
	{
		private :
			int value;
		public :
			GJsonInt(int _value) : GJsonValue(int_value),value(_value) {}
			std::string stringify();
	};

	class GJsonReal : public GJsonValue
	{
		private : 
			double value;
		public :
			GJsonReal(double _value) : GJsonValue(real_value),value(_value) {}
			std::string stringify();
	};

	class GJsonString : public GJsonValue 
	{
		private : 
			std::string value;
		public:
			GJsonString(std::string &_value) : GJsonValue(string_value)
			{
				value = _value; //copy
			}
			std::string stringify();
	};

	class GJsonBool : public GJsonValue 
	{
		private :
			bool value;
		public :
			GJsonBool(bool _value) : GJsonValue(bool_value),value(_value) {}
			std::string stringify();
	};

	/*An array can contain any type of value
	 * eg [1,2,"x",{"y":1234}*/
	class GJsonArray : public GJsonValue 
	{
		private :
			/*Needs a holder to hold any type of data*/
			<typename valueType>
			class holder {
				
			};

	};
END_GJSON_NAMESPACE

#endif /*__GJSONVALUE_h__*/
