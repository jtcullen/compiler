#ifndef COMPILER_GREATERTHANEQUAL_H
#define COMPILER_GREATERTHANEQUAL_H

#include "BinaryExpression.h"
#include <iostream>

class GreaterThanEqual: public BinaryExpression
{
public:
    GreaterThanEqual(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_GREATERTHANEQUAL_H