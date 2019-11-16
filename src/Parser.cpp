#include "Parser.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Complement.h"
#include "Negation.h"
#include "Negative.h"
#include "And.h"
#include "Equal.h"
#include "GreaterThan.h"
#include "GreaterThanEqual.h"
#include "LessThan.h"
#include "LessThanEqual.h"
#include "NotEqual.h"
#include "Or.h"
#include "Declaration.h"
#include "Assignment.h"
#include "Variable.h"

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

    std::vector<Statement *> statements;
    while (token(0).getType() != Token::Type::END)
    {
        Statement *statement = parseStatement();
        statements.push_back(statement);
    }

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

    return new Function(name, statements);
}

Statement *Parser::parseStatement()
{
    Statement *statement;
    if (token(0).getType() == Token::Type::RETURN)
    {
        nextToken();
        Expression *exp = parseExpression();
        statement = new Return(exp);
    }
    else if (token(0).getType() == Token::Type::INTEGER)
    {
        Expression *exp = nullptr;
        nextToken();

        if (token(0).getType() != Token::Type::IDENTIFIER)
        {
            throw "Expected IDENTIFIER";
        }
        std::string identifier = token(0).getValue();
        nextToken();

        if (token(0).getType() != Token::Type::SEMICOLON)
        {
            if (token(0).getType() != Token::Type::ASSIGNMENT)
            {
                throw "Expected ASSIGNMENT";
            }
            nextToken();

            exp = parseExpression();
        }

        statement = new Declaration(identifier, exp);
    }
    else
    {
        statement = parseExpression();
    }

    if (token(0).getType() != Token::Type::SEMICOLON)
    {
        throw "Expected SEMICOLON";
    }
    nextToken();

    return statement;
}

Expression *Parser::parseLogicalOrExpression()
{
    Expression *left = parseLogicalAndExpression();
    while (token(0).getType() == Token::Type::LOGICAL_OR)
    {
        if (token(0).getType() == Token::Type::LOGICAL_OR)
        {
            nextToken();
            left = new Or(left, parseLogicalAndExpression());
        }
    }

    return left;
}

Expression *Parser::parseLogicalAndExpression()
{
    Expression *left = parseRelationalEqualExpression();
    while (token(0).getType() == Token::Type::LOGICAL_AND)
    {
        if (token(0).getType() == Token::Type::LOGICAL_AND)
        {
            nextToken();
            left = new And(left, parseRelationalEqualExpression());
        }
    }

    return left;
}

Expression *Parser::parseRelationalEqualExpression()
{
    Expression *left = parseRelationalExpression();
    while (token(0).getType() == Token::Type::EQUAL || token(0).getType() == Token::Type::NOT_EQUAL)
    {
        if (token(0).getType() == Token::Type::EQUAL)
        {
            nextToken();
            left = new Equal(left, parseRelationalExpression());
        }
        else if (token(0).getType() == Token::Type::NOT_EQUAL)
        {
            nextToken();
            left = new NotEqual(left, parseRelationalExpression());
        }
    }

    return left;
}

Expression *Parser::parseRelationalExpression()
{
    Expression *left = parseAddititveExpression();
    while (token(0).getType() == Token::Type::LESS_THAN || token(0).getType() == Token::Type::GREATER_THAN ||
           token(0).getType() == Token::Type::LESS_THAN_EQUAL || token(0).getType() == Token::Type::GREATER_THAN_EQUAL)
    {
        if (token(0).getType() == Token::Type::LESS_THAN)
        {
            nextToken();
            left = new LessThan(left, parseAddititveExpression());
        }
        else if (token(0).getType() == Token::Type::GREATER_THAN)
        {
            nextToken();
            left = new GreaterThan(left, parseAddititveExpression());
        }
        else if (token(0).getType() == Token::Type::LESS_THAN_EQUAL)
        {
            nextToken();
            left = new LessThanEqual(left, parseAddititveExpression());
        }
        else if (token(0).getType() == Token::Type::GREATER_THAN_EQUAL)
        {
            nextToken();
            left = new GreaterThanEqual(left, parseAddititveExpression());
        }
    }

    return left;
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
    else if (token(0).getType() == Token::Type::IDENTIFIER)
    {
        exp = new Variable(token(0).getValue());
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
    Expression *exp;
    if (token(0).getType() == Token::Type::IDENTIFIER && token(1).getType() == Token::Type::ASSIGNMENT)
    {
        std::string identifier = token(0).getValue();
        nextToken();

        if (token(0).getType() != Token::Type::ASSIGNMENT)
        {
            throw "Expected ASSIGNMENT";
        }
        nextToken();

        exp = new Assignment(identifier, parseExpression());
    }
    else
    {
        exp = parseLogicalOrExpression();
    }

    return exp;
}
