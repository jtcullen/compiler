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
#include "If.h"
#include "Break.h"
#include "Continue.h"
#include "For.h"
#include "NullStatement.h"
#include "While.h"

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

Token Parser::expect(Token::Type tokenType)
{
    Token t = token(0);
    if (t.getType() != tokenType)
    {
        throw "Expected a token of type: " + tokenType;
    }
    nextToken();

    return t;
}

bool Parser::accept(Token::Type tokenType)
{
    Token t = token(0);
    if (t.getType() == tokenType)
    {
        nextToken();
        return true;
    }

    return false;
}

Program *Parser::parse()
{
    return new Program(parseFunction());
}

Block *Parser::parseBlock()
{
    expect(Token::Type::BEGIN);

    std::vector<BlockItem *> blockItems;
    while (token(0).getType() != Token::Type::END)
    {
        BlockItem *blockItem = parseBlockItem();
        blockItems.push_back(blockItem);
    }

    expect(Token::Type::END);

    return new Block(blockItems);
}

Function *Parser::parseFunction()
{
    expect(Token::Type::INTEGER);

    std::string name = expect(Token::Type::IDENTIFIER).getValue();

    expect(Token::Type::L_PAREN);
    expect(Token::Type::R_PAREN);

    Block *block = parseBlock();

    expect(Token::Type::END_OF_FILE);

    return new Function(name, block);
}

BlockItem *Parser::parseBlockItem()
{
    BlockItem *blockItem;

    if (accept(Token::Type::INTEGER))
    {
        Expression *exp = nullptr;

        std::string identifier = expect(Token::Type::IDENTIFIER).getValue();

        if (token(0).getType() != Token::Type::SEMICOLON)
        {
            expect(Token::Type::ASSIGNMENT);

            exp = parseExpression();
        }

        blockItem = new Declaration(identifier, exp);

        expect(Token::Type::SEMICOLON);
    }
    else
    {
        blockItem = parseStatement();
    }

    return blockItem;
}

Statement *Parser::parseStatement()
{
    Statement *statement;
    if (accept(Token::Type::RETURN))
    {
        Expression *exp = parseExpression();
        statement = new Return(exp);

        expect(Token::Type::SEMICOLON);
    }
    else if (accept(Token::Type::IF))
    {
        expect(Token::Type::L_PAREN);

        Expression *exp = parseExpression();

        expect(Token::Type::R_PAREN);

        Statement *ifStatement = parseStatement();
        Statement *elseStatement = nullptr;

        if (accept(Token::Type::ELSE))
        {
            elseStatement = parseStatement();
        }

        statement = new If(exp, ifStatement, elseStatement);
    }
    else if (token(0).getType() == Token::Type::BEGIN)
    {
        statement = parseBlock();
    }
    else if (accept(Token::Type::SEMICOLON))
    {
        statement = new NullStatement();
    }
    else if (accept(Token::Type::FOR))
    {
        expect(Token::Type::L_PAREN);

        Expression *assign = nullptr;
        if (token(0).getType() != Token::Type::SEMICOLON)
        {
            assign = parseExpression();
        }

        expect(Token::Type::SEMICOLON);

        Expression *control = nullptr;
        if (token(0).getType() != Token::Type::SEMICOLON)
        {
            control = parseExpression();
        }

        expect(Token::Type::SEMICOLON);

        Expression *inc = nullptr;
        if (token(0).getType() != Token::Type::R_PAREN)
        {
            inc = parseExpression();
        }

        expect(Token::Type::R_PAREN);

        Statement *body = parseStatement();

        statement = new For(assign, control, inc, body);
    }
    else if (accept(Token::Type::WHILE))
    {
        expect(Token::Type::L_PAREN);

        Expression *control = parseExpression();

        expect(Token::Type::R_PAREN);

        Statement *body = parseStatement();

        statement = new While(control, body);
    }
    else if (accept(Token::Type::BREAK))
    {
        statement = new Break();

        expect(Token::Type::SEMICOLON);
    }
    else if (accept(Token::Type::CONTINUE))
    {
        statement = new Continue();

        expect(Token::Type::SEMICOLON);
    }
    else
    {
        statement = parseExpression();

        expect(Token::Type::SEMICOLON);
    }

    return statement;
}

Expression *Parser::parseLogicalOrExpression()
{
    Expression *left = parseLogicalAndExpression();
    while (token(0).getType() == Token::Type::LOGICAL_OR)
    {
        if (accept(Token::Type::LOGICAL_OR))
        {
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
        if (accept(Token::Type::LOGICAL_AND))
        {
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
        if (accept(Token::Type::EQUAL))
        {
            left = new Equal(left, parseRelationalExpression());
        }
        else if (accept(Token::Type::NOT_EQUAL))
        {
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
        if (accept(Token::Type::LESS_THAN))
        {
            left = new LessThan(left, parseAddititveExpression());
        }
        else if (accept(Token::Type::GREATER_THAN))
        {
            left = new GreaterThan(left, parseAddititveExpression());
        }
        else if (accept(Token::Type::LESS_THAN_EQUAL))
        {
            left = new LessThanEqual(left, parseAddititveExpression());
        }
        else if (accept(Token::Type::GREATER_THAN_EQUAL))
        {
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
        if (accept(Token::Type::PLUS))
        {
            left = new Addition(left, parseMultiplicativeExpression());
        }
        else if (accept(Token::Type::MINUS))
        {
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
        if (accept(Token::Type::STAR))
        {
            left = new Multiplication(left, parseUnaryExpression());
        }
        else if (accept(Token::Type::SLASH))
        {
            left = new Division(left, parseUnaryExpression());
        }
    }

    return left;
}

Expression *Parser::parseUnaryExpression()
{
    Expression *exp;
    if (accept(Token::Type::SQUIGLY))
    {
        exp = new Complement(parseUnaryExpression());
    }
    else if (accept(Token::Type::EXCLAMATION))
    {
        exp = new Negation(parseUnaryExpression());
    }
    else if (accept(Token::Type::MINUS))
    {
        exp = new Negative(parseUnaryExpression());
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
    if (accept(Token::Type::L_PAREN))
    {
        exp = parseExpression();

        expect(Token::Type::R_PAREN);
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

        expect(Token::Type::ASSIGNMENT);

        exp = new Assignment(identifier, parseExpression());
    }
    else
    {
        exp = parseLogicalOrExpression();
    }

    return exp;
}
