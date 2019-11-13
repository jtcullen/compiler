#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include <iostream>
#include <string>

class Token
{
public:
    enum Type
    {
        INTEGER,
        PRINT,
        BEGIN,
        END,
        RETURN,
        L_PAREN,
        R_PAREN,
        SEMICOLON,
        SQUIGLY,
        EXCLAMATION,
        MINUS,
        INTEGER_LITERAL,
        STRING_LITERAL,
        IDENTIFIER,
        UNKNOWN,
        END_OF_FILE
    };

private:
    Type type;
    std::string value;

public:
    Token(Type type, std::string::iterator begin, std::string::iterator end);
    Type getType();
    std::string getValue();
    friend std::ostream& operator<<(std::ostream& os, const Token& tk);
};

#endif //COMPILER_TOKEN_H