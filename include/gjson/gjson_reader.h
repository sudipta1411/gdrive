#ifndef __GJSON_READER_H__
#define __GJSON_READER_H__
#include <stack>
#include <vector>
#include "gjson/gjson_type.h"
#include "gjson/gjson_value.h"

BEGIN_GJSON_NAMESPACE
    class GJsonReader
    {
        private :
            std::stack<char> _stack;
            const char* begin;
            const char* end;
            const char* current;

            std::string doc;

            struct Token
            {
                token_type_t type;
                const char* begin;
                const char* end;
            };

            struct Error
            {
                Token *tok;
                size_t begin;
                std::string errMsg;
            };

            GJsonMap *root; //root map
            std::vector<Error*> errors;

            void skipWhiteSpace();
            bool isWhiteSpace(char ch);
            Token* readNextToken();
            char getNextChar();
            bool containsNewline(const char*_begin,const char* _end);
            void addError(Error& err);
            bool isEqualToChar(char c);
            /*read methods for basic json datatypes.
             * NOTE : these functions uses the _stack
             * e.g
             * if(getNextChar()=='\"')
             *     _stack.push('\"');
             *     JSON_STRING = readString();
             * readXXX method is responsible for popping relevant token
             * from _stack and relevant error handling
            * */
            GJsonString* readString();
            GJsonLong* readLong();
            GJsonReal* readReal();
            GJsonBool* readBool(char cur);

            /*read methods for compound data type(array,object)
             * the above comment applies here as well
            */
            GJsonArray* readArray();
            GJsonMap* readObject();
            /*NOTE : a json object is everything between '{' and '}'
             * Where as a JSON map is a key-value pair, where the key is a string,
             * abd value can be any JSON type value(e.g another object,array,
             * string etc). A json object can contain multiple key-value pair,
             * seperated with comma.
            * */
            GJsonMap* readMap();
            //bool readArrayToken(Token* token);
            /*Error* getError() const;*/
        public :
            GJsonReader();
            GJsonReader(const std::string& _doc);
            ~GJsonReader();
            bool parse(const std::string& _doc);
            bool parse();
            GenericValue* getValue(const std::string& key) const;
            bool ok() const;
    };
END_GJSON_NAMESPACE
#endif /*__GJSON_READER_H__*/
