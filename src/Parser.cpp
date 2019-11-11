#include "Parser.h"

Parser::Parser(Lexer &lexer) : lexer(lexer), lookaheadBufferPos(0) {

    // Set up lookahead buffer
    for (size_t i = 0; i < LOOKAHEAD; i++)
    {
        lookaheadBuffer.push_back(lexer.nextToken());
    }    
}

Token Parser::nextToken(){
    Token next = lookaheadBuffer.at(lookaheadBufferPos);

    lookaheadBuffer.at(lookaheadBufferPos) = lexer.nextToken();
    lookaheadBufferPos = (lookaheadBufferPos + 1) % lookaheadBuffer.size();

    return next;
}

Token Parser::lookahead(int i){
    return lookaheadBuffer.at((lookaheadBufferPos + i) % lookaheadBuffer.size());
}

void Parser::parse(){
    Token token = nextToken();
    while (token.getType() != Token::Type::END_OF_FILE)
    {
        std::cout << token << std::endl;
        std::cout << lookahead(0) << std::endl;
        std::cout << lookahead(1) << std::endl;
        token = nextToken();
    }
}
