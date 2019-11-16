#ifndef COMPILER_LESSTHAN_H
#define COMPILER_LESSTHAN_H

#include "BinaryExpression.h"
#include <iostream>

class LessThan: public BinaryExpression
{
public:
    LessThan(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_LESSTHAN_H