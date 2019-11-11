#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#include<string>
#include <vector> 
#include "Token.h"

class Lexer {
private:
    std::string input;
    std::string::iterator cursor;
    std::string::iterator limit;
public:
    Lexer(std::string &input);

    Token nextToken();
};


#endif //COMPILER_LEXER_H