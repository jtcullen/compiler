#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include <vector>
#include "Lexer.h"

#define LOOKAHEAD 2

class Parser
{
private:
    Lexer &lexer;
    std::vector<Token> lookaheadBuffer;
    int lookaheadBufferPos;
    Token nextToken();
    Token lookahead(int i);
public:
    Parser(Lexer &lexer);
    void parse();
};

#endif //COMPILER_PARSER_H