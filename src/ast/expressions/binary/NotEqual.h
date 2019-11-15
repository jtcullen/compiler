#ifndef COMPILER_NOTEQUAL_H
#define COMPILER_NOTEQUAL_H

#include "BinaryExpression.h"
#include <iostream>

class NotEqual: public BinaryExpression
{
public:
    NotEqual(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_NOTEQUAL_H