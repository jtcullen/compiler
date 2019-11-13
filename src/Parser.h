#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include <vector>
#include "Integer.h"
#include "Return.h"
#include "Function.h"
#include "Program.h"
#include "Lexer.h"

#define LOOKAHEAD 0

class Parser
{
private:
    Lexer &lexer;
    std::vector<Token> buffer;
    int bufferPos;
    void nextToken();
    Token token(int i);
    Expression *parseExpression();
    Return *parseReturn();
    Function *parseFunction();
public:
    Parser(Lexer &lexer);
    
    Program *parse();
};

#endif //COMPILER_PARSER_H