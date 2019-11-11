#include "Parser.h"

Parser::Parser(Lexer &lexer) : lexer(lexer), lookaheadBufferPos(0)
{

    // Set up lookahead buffer
    for (size_t i = 0; i < LOOKAHEAD; i++)
    {
        lookaheadBuffer.push_back(lexer.nextToken());
    }
}

Token Parser::nextToken()
{
    Token next = lookaheadBuffer.at(lookaheadBufferPos);

    lookaheadBuffer.at(lookaheadBufferPos) = lexer.nextToken();
    lookaheadBufferPos = (lookaheadBufferPos + 1) % lookaheadBuffer.size();

    return next;
}

Token Parser::lookahead(int i)
{
    return lookaheadBuffer.at((lookaheadBufferPos + i) % lookaheadBuffer.size());
}

Program Parser::parse()
{
    return Program(parseFunction());
}

Function Parser::parseFunction()
{
    Token token = nextToken();

    if (token.getType() != Token::Type::INTEGER)
    {
        throw "Expected Integer";
    }
    token = nextToken();

    if (token.getType() != Token::Type::IDENTIFIER)
    {
        throw "Expected Identifier";
    }
    std::string name = token.getValue();
    token = nextToken();

    if (token.getType() != Token::Type::L_PAREN)
    {
        throw "Expected Opening Parentheses";
    }
    token = nextToken();

    if (token.getType() != Token::Type::R_PAREN)
    {
        throw "Expected Closing Parentheses";
    }
    token = nextToken();

    if (token.getType() != Token::Type::BEGIN)
    {
        throw "Expected BEGIN";
    }

    Return ret = parseReturn();

    token = nextToken();
    if (token.getType() != Token::Type::END)
    {
        throw "Expected END";
    }

    return Function(name, ret);
}

Return Parser::parseReturn()
{
    Token token = nextToken();

    if (token.getType() != Token::Type::RETURN)
    {
        throw "Expected RETURN";
    }

    Integer integer = parseInteger();

    token = nextToken();
    if (token.getType() != Token::Type::SEMICOLON)
    {
        throw "Expected SEMICOLON";
    }

    return Return(integer);
}

Integer Parser::parseInteger()
{
    Token token = nextToken();

    if (token.getType() != Token::Type::INTEGER_LITERAL)
    {
        throw "Expected integer literal";
    }

    return Integer(stoi(token.getValue()));
}
