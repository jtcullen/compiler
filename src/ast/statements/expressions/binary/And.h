#ifndef COMPILER_AND_H
#define COMPILER_AND_H

#include "BinaryExpression.h"
#include <iostream>

class And: public BinaryExpression
{
public:
    And(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_AND_H