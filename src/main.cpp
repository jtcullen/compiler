#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include "Lexer.h"
#include "Parser.h"

// TODO: validate integer size
// TODO: validate main function exists

int main(int argc, char const *argv[])
{
    std::ifstream t("/home/jt/Documents/compiler/examples/return_43.idk");
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    Lexer lexer(str);
    Parser parser(lexer);

    std::cout << "AST:" << std::endl;
    Program program = parser.parse();
    program.print();

    AssemblyProgram ap = program.generate();
    std::cout << std::endl << "Assembly:" << std::endl << ap;
    
    return 0;
}
