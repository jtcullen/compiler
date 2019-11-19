#ifndef COMPILER_CONTINUE_H
#define COMPILER_CONTINUE_H

#include <iostream>
#include "Statement.h"
#include "Expression.h"
#include "AssemblyProgram.h"

class Continue : public Statement
{
public:
    Continue();
    ~Continue();
    void print(std::ostream &os, int indent) const;
    void generate(AssemblyProgram &ap) const;
    friend std::ostream &operator<<(std::ostream &os, const Continue &ret);
};

#endif //COMPILER_CONTINUE_H