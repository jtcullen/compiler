#ifndef COMPILER_MULTIPLICATION_H
#define COMPILER_MULTIPLICATION_H

#include "BinaryExpression.h"
#include <iostream>

class Multiplication: public BinaryExpression
{
public:
    Multiplication(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_MULTIPLICATION_H