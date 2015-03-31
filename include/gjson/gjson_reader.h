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

            struct node
            {
                GenericValue *value;
                node* child;
                node* sibling;
                node* parent;
            };

            struct token
            {
                token_type_t type;
                char* begin;
                char* end;
            };

            struct error
            {
                token *tok;
                size_t begin;
                std::string errMsg;
            };

            node *root;
            std::vector<error*> errors;

            void skipWhiteSpace();
            token* readNextToken();
            char getNextChar();
            bool containsNewline(const char*_begin,const char* _end);
            void addError(error* err);
            error* getError() const;
        public :
            GJsonReader();
            GJsonReader(std::string& _doc);
            void parse(std::string& _doc);
            void parse();
    };
END_GJSON_NAMESPACE
#endif /*__GJSON_READER_H__*/
