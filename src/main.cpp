#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include "Lexer.h"

int main(int argc, char const *argv[])
{
    std::ifstream t("./examples/return.idk");
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    Lexer Lexer(str);
    
    Token token = Lexer.nextToken();
    while (token.getType() != Token::Type::END_OF_FILE)
    {
        std::cout << token << std::endl;
        token = Lexer.nextToken();
    }
    
    return 0;
}
