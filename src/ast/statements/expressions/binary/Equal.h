#ifndef COMPILER_EQUAL_H
#define COMPILER_EQUAL_H

#include "BinaryExpression.h"
#include <iostream>

class Equal: public BinaryExpression
{
public:
    Equal(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_EQUAL_H