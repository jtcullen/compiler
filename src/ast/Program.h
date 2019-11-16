#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include <iostream>
#include "ASTNode.h"
#include "Function.h"
#include "AssemblyProgram.h"

class Program : public ASTNode
{
private:
    Function *function;
public:
    Program(Function *function);
    ~Program();
    void generate(AssemblyProgram &ap) const;
    void print(int indent = 0) const;
    friend std::ostream& operator<<(std::ostream& os, const Program& pr);
};

#endif //COMPILER_PROGRAM_H