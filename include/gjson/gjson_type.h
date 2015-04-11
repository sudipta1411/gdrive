#ifndef __GJSONTYPE_H__
#define __GJSONTYPE_H__

#define GJSON gjson
#define BEGIN_GJSON_NAMESPACE namespace GJSON {
#define END_GJSON_NAMESPACE } /*namespace gjson*/

/*Various token type*/
#define ARRAY_BEGIN '['
#define ARRAY_END ']'
#define OBJECT_BEGIN '{'
#define OBJECT_END '}'
#define STRING_BEGIN '"'
#define STRING_END STRING_BEGIN
#define STRINF_BEGIN_1 '\''
#define STRING_END_1 STRINF_BEGIN_1
#define SEPERATOR ','
#define MEMBER_SEPERATOR ':'

/*type of value in json format*/
enum value_type_t
{
	null_value = 0,
	int_value,
	long_value,
	real_value,
	string_value,
	bool_value,
	array_value,
	object_value
};

enum token_type_t
{
	/*token_array_begin=1,
	token_array_end,*/
    token_array = 1,
	/*token_object_begin,
	token_object_end,*/
    token_object,
	token_string,
	token_number,
	token_boolean
};
#endif /*__GJSONTYPE_H__*/
