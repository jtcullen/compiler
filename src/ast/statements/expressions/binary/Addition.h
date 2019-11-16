#ifndef COMPILER_ADDITION_H
#define COMPILER_ADDITION_H

#include "BinaryExpression.h"
#include <iostream>

class Addition: public BinaryExpression
{
public:
    Addition(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_ADDITION_H