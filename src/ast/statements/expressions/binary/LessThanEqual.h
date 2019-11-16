#ifndef COMPILER_LESSTHANEQUAL_H
#define COMPILER_LESSTHANEQUAL_H

#include "BinaryExpression.h"
#include <iostream>

class LessThanEqual: public BinaryExpression
{
public:
    LessThanEqual(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_LESSTHANEQUAL_H