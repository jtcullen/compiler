#include "Parser.h"

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

Program Parser::parse()
{
    return Program(parseFunction());
}

Function Parser::parseFunction()
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

    Return ret = parseReturn();

    if (token(0).getType() != Token::Type::END)
    {
        throw "Expected END";
    }
    nextToken();

    return Function(name, ret);
}

Return Parser::parseReturn()
{
    if (token(0).getType() != Token::Type::RETURN)
    {
        throw "Expected RETURN";
    }
    nextToken();

    Integer integer = parseInteger();

    if (token(0).getType() != Token::Type::SEMICOLON)
    {
        throw "Expected SEMICOLON";
    }
    nextToken();

    return Return(integer);
}

Integer Parser::parseInteger()
{
    if (token(0).getType() != Token::Type::INTEGER_LITERAL)
    {
        throw "Expected integer literal";
    }
    Integer parsed = Integer(stoi(token(0).getValue()));
    nextToken();

    return parsed;
}
