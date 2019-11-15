#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H

#include "AssemblyProgram.h"

class Expression
{
public:
    virtual ~Expression() {};
    virtual void generate(AssemblyProgram &ap) const = 0;
    virtual void print(int indent) const = 0;
};

#endif //COMPILER_EXPRESSION_H