#ifndef COMPILER_DIVISION_H
#define COMPILER_DIVISION_H

#include "BinaryExpression.h"
#include <iostream>

class Division: public BinaryExpression
{
public:
    Division(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_DIVISION_H