#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include <iostream>
#include "Function.h"
#include "AssemblyProgram.h"

class Program
{
private:
    Function *function;
public:
    Program(Function *function);
    ~Program();
    AssemblyProgram generate();
    void print(int indent = 0);
    friend std::ostream& operator<<(std::ostream& os, const Program& pr);
};

#endif //COMPILER_PROGRAM_H