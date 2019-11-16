#ifndef COMPILER_OR_H
#define COMPILER_OR_H

#include "BinaryExpression.h"
#include <iostream>

class Or: public BinaryExpression
{
public:
    Or(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_OR_H