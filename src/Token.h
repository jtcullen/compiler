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
        IF,
        ELSE,
        FOR,
        WHILE,
        DO,
        BREAK,
        CONTINUE,
        L_PAREN,
        R_PAREN,
        COLON,
        Q_MARK,
        SEMICOLON,
        SQUIGLY,
        EXCLAMATION,
        PLUS,
        MINUS,
        STAR,
        SLASH,
        LOGICAL_AND,
        LOGICAL_OR,
        EQUAL,
        NOT_EQUAL,
        LESS_THAN,
        LESS_THAN_EQUAL,
        GREATER_THAN,
        GREATER_THAN_EQUAL,
        ASSIGNMENT,
        INTEGER_LITERAL,
        STRING_LITERAL,
        IDENTIFIER,
        UNKNOWN,
        END_OF_FILE
    };

private:
    Type type;
    std::string value;
    std::bool isValidInt;
public:
    std::bool getIsValidInt(){return isValidInt;}
    void setIsValidInt(std::bool x){isValidInt = x;}
    Token(Type type, std::string::iterator begin, std::string::iterator end);
    Type getType();
    std::string getValue();
    friend std::ostream& operator<<(std::ostream& os, const Token& tk);
};

#endif //COMPILER_TOKEN_H
