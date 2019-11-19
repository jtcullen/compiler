#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include "Lexer.h"
#include "Parser.h"

// TODO: validate integer size

int main(int argc, char const *argv[])
{
    std::string file;
    std::string outname = "a";
    if (argc < 2)
    {
        std::cout << "Correct usage is: " << argv[0] << " input-file [output-name]" << std::endl;
        return 1;
    }

    file = argv[1];

    if (argc > 2)
    {
        outname = argv[2];
    }

    // Read file into a string
    std::ifstream f(file);
    std::string str((std::istreambuf_iterator<char>(f)),
                    std::istreambuf_iterator<char>());

    // Open our output files
    std::fstream tree;
    std::fstream asembly;
    tree.open(outname + ".ast", std::ios::out | std::ios::trunc);
    asembly.open(outname + ".asm", std::ios::out | std::ios::trunc);

    AssemblyProgram ap;
    Lexer lexer(str);
    Parser parser(lexer);

    try
    {
        // Parse the program
        Program *program = parser.parse();

        // Write ast to file
        program->print(tree);

        // Generate assembly, write to file
        program->generate(ap);
        asembly << ap;

        if (!ap.getMainFlag())
        {
            throw "No main function specified!";
        }

        // Compile the program
        system(("nasm -f elf32 " + outname + ".asm" + " -o " + outname + ".o").c_str());

        // Link the program
        system(("ld -m elf_i386 " + outname + ".o -o " + outname).c_str());

        delete program;
        program = nullptr;
    }
    catch (const std::exception &exc)
    {
        std::cout << exc.what();
    }

    return 0;
}
