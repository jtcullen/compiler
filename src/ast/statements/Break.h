#ifndef COMPILER_BREAK_H
#define COMPILER_BREAK_H

#include <iostream>
#include "Statement.h"
#include "Expression.h"
#include "AssemblyProgram.h"

class Break : public Statement
{
public:
    Break();
    ~Break();
    void print(int indent) const;
    void generate(AssemblyProgram &ap) const;
    friend std::ostream &operator<<(std::ostream &os, const Break &ret);
};

#endif //COMPILER_BREAK_H