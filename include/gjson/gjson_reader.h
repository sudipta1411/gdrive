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
              the above comment applies here as well
            */
            GJsonArray* readArray();
            GJsonMap* readObject();

            //bool readArrayToken(Token* token);
            /*Error* getError() const;*/
        public :
            GJsonReader();
            GJsonReader(std::string& _doc);
            void parse(std::string& _doc);
            void parse();
    };
END_GJSON_NAMESPACE
#endif /*__GJSON_READER_H__*/
