#include "Parser.h"
#include "Complement.h"
#include "Negation.h"
#include "Negative.h"

Parser::Parser(Lexer &lexer) : lexer(lexer), bufferPos(0)
{

    // Set up lookahead buffer
    for (size_t i = 0; i < LOOKAHEAD + 1; i++)
    {
        buffer.push_back(lexer.nextToken());
    }
}

void Parser::nextToken()
{
    buffer.at(bufferPos) = lexer.nextToken();
    bufferPos = (bufferPos + 1) % buffer.size();
}

Token Parser::token(int i)
{
    return buffer.at((bufferPos + i) % buffer.size());
}

Program *Parser::parse()
{
    return new Program(parseFunction());
}

Function *Parser::parseFunction()
{
    if (token(0).getType() != Token::Type::INTEGER)
    {
        throw "Expected Integer";
    }
    nextToken();

    if (token(0).getType() != Token::Type::IDENTIFIER)
    {
        throw "Expected Identifier";
    }
    std::string name = token(0).getValue();
    nextToken();

    if (token(0).getType() != Token::Type::L_PAREN)
    {
        throw "Expected Opening Parentheses";
    }
    nextToken();

    if (token(0).getType() != Token::Type::R_PAREN)
    {
        throw "Expected Closing Parentheses";
    }
    nextToken();

    if (token(0).getType() != Token::Type::BEGIN)
    {
        throw "Expected BEGIN";
    }
    nextToken();

    Return *ret = parseReturn();

    if (token(0).getType() != Token::Type::END)
    {
        throw "Expected END";
    }
    nextToken();

    if (token(0).getType() != Token::Type::END_OF_FILE)
    {
        throw "Expected End of File";
    }
    nextToken();

    return new Function(name, ret);
}

Return *Parser::parseReturn()
{
    if (token(0).getType() != Token::Type::RETURN)
    {
        throw "Expected RETURN";
    }
    nextToken();

    Expression *exp = parseExpression();

    if (token(0).getType() != Token::Type::SEMICOLON)
    {
        throw "Expected SEMICOLON";
    }
    nextToken();

    return new Return(exp);
}

Expression *Parser::parseExpression()
{
    Expression *exp;
    if (token(0).getType() == Token::Type::INTEGER_LITERAL)
    {
        exp = new Integer(stoi(token(0).getValue()));
        nextToken();
    }
    else if (token(0).getType() == Token::Type::SQUIGLY)
    {
        nextToken();
        exp = new Complement(parseExpression());
    }
    else if (token(0).getType() == Token::Type::EXCLAMATION)
    {
        nextToken();
        exp = new Negation(parseExpression());
    }
    else if (token(0).getType() == Token::Type::MINUS)
    {
        nextToken();
        exp = new Negative(parseExpression());
    }
    else
    {
        throw "Expected an expression";
    }

    return exp;
}
