#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include <vector>
#include "Integer.h"
#include "Return.h"
#include "Function.h"
#include "Program.h"
#include "Lexer.h"

#define LOOKAHEAD 1

class Parser
{
private:
    Lexer &lexer;
    std::vector<Token> buffer;
    int bufferPos;
    void nextToken();
    Token token(int i);
    Expression *parseLogicalOrExpression();
    Expression *parseLogicalAndExpression();
    Expression *parseRelationalEqualExpression();
    Expression *parseRelationalExpression();
    Expression *parseAddititveExpression();
    Expression *parseMultiplicativeExpression();
    Expression *parseUnaryExpression();
    Expression *parsePrimaryExpression();
    Expression *parseExpression();
    BlockItem *parseBlockItem();
    Statement *parseStatement();
    Function *parseFunction();
public:
    Parser(Lexer &lexer);
    
    Program *parse();
};

#endif //COMPILER_PARSER_H