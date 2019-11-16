#ifndef COMPILER_NEGATIVE_H
#define COMPILER_NEGATIVE_H

#include "UnaryExpression.h"
#include <iostream>

class Negative: public UnaryExpression
{
public:
    Negative(Expression *exp) : UnaryExpression(exp) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_NEGATIVE_H