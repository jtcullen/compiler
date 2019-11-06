#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#include<string>

class Lexer {
private:
    std::string input;
    std::string::iterator cursor;
    std::string::iterator limit;
public:
    enum Token {
        INTEGER,
        PRINT,
        BEGIN,
        END,
        RETURN,
        L_PAREN,
        R_PAREN,
        SEMICOLON,
        INTEGER_LITERAL,
        STRING_LITERAL,
        IDENTIFIER,
        UNKNOWN,
        END_OF_FILE
    };

    Lexer(std::string &input);

    Token nextToken();
};


#endif //COMPILER_LEXER_H