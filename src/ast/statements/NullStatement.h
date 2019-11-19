#ifndef COMPILER_NULLSTATEMENT_H
#define COMPILER_NULLSTATEMENT_H

#include <iostream>
#include "Statement.h"
#include "AssemblyProgram.h"

class NullStatement : public Statement
{
public:
    NullStatement();
    ~NullStatement();
    void print(std::ostream &os, int indent) const;
    void generate(AssemblyProgram &ap) const;
    friend std::ostream &operator<<(std::ostream &os, const NullStatement &ret);
};

#endif //COMPILER_NULLSTATEMENT_H