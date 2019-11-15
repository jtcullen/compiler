#ifndef COMPILER_GREATERTHAN_H
#define COMPILER_GREATERTHAN_H

#include "BinaryExpression.h"
#include <iostream>

class GreaterThan: public BinaryExpression
{
public:
    GreaterThan(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_GREATERTHAN_H