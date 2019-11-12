#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include <iostream>
#include "Function.h"
#include "ASTNode.h"

class Program: public ASTNode
{
private:
    Function function;
public:
    Program(Function function);
    void print(int indent = 0);
    friend std::ostream& operator<<(std::ostream& os, const Program& pr);
};

#endif //COMPILER_PROGRAM_H