#ifndef COMPILER_SUBTRACTION_H
#define COMPILER_SUBTRACTION_H

#include "BinaryExpression.h"
#include <iostream>

class Subtraction: public BinaryExpression
{
public:
    Subtraction(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_SUBTRACTION_H