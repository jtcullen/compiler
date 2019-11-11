#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include <vector>
#include "Integer.h"
#include "Return.h"
#include "Function.h"
#include "Program.h"
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
    Integer parseInteger();
    Return parseReturn();
    Function parseFunction();
public:
    Parser(Lexer &lexer);
    Program parse();
};

#endif //COMPILER_PARSER_H