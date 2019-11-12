#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char const *argv[])
{
    std::ifstream t("/home/jt/Documents/compiler/examples/return.idk");
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    Lexer lexer(str);
    Parser parser(lexer);

    Program program = parser.parse();
    program.print();
    
    return 0;
}
