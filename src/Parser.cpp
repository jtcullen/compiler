#include "Parser.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
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

Expression *Parser::parseAddititveExpression()
{
    Expression *left = parseMultiplicativeExpression();
    while (token(0).getType() == Token::Type::PLUS || token(0).getType() == Token::Type::MINUS)
    {
        if (token(0).getType() == Token::Type::PLUS)
        {
            nextToken();
            left = new Addition(left, parseMultiplicativeExpression());
        }
        else if (token(0).getType() == Token::Type::MINUS)
        {
            nextToken();
            left = new Subtraction(left, parseMultiplicativeExpression());
        }
    }

    return left;
}

Expression *Parser::parseMultiplicativeExpression()
{
    Expression *left = parseUnaryExpression();
    while (token(0).getType() == Token::Type::STAR || token(0).getType() == Token::Type::SLASH)
    {
        if (token(0).getType() == Token::Type::STAR)
        {
            nextToken();
            left = new Multiplication(left, parseUnaryExpression());
        }
        else if (token(0).getType() == Token::Type::SLASH)
        {
            nextToken();
            left = new Division(left, parseUnaryExpression());
        }
    }

    return left;
}

Expression *Parser::parseUnaryExpression()
{
    Expression *exp;
    if (token(0).getType() == Token::Type::SQUIGLY)
    {
        nextToken();
        exp = new Complement(parsePrimaryExpression());
    }
    else if (token(0).getType() == Token::Type::EXCLAMATION)
    {
        nextToken();
        exp = new Negation(parsePrimaryExpression());
    }
    else if (token(0).getType() == Token::Type::MINUS)
    {
        nextToken();
        exp = new Negative(parsePrimaryExpression());
    }
    else
    {
        exp = parsePrimaryExpression();
    }

    return exp;
}

Expression *Parser::parsePrimaryExpression()
{
    Expression *exp;
    if (token(0).getType() == Token::Type::L_PAREN)
    {
        nextToken();
        exp = parseExpression();

        if (token(0).getType() != Token::Type::R_PAREN)
        {
            throw "Expected closing parentheses";
        }
        nextToken();
    }
    else if (token(0).getType() == Token::Type::INTEGER_LITERAL)
    {
        exp = new Integer(stoi(token(0).getValue()));
        nextToken();
    }
    else
    {
        throw "Expected a primary expression";
    }

    return exp;
}

Expression *Parser::parseExpression()
{
    return parseAddititveExpression();
}
