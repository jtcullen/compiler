#ifndef COMPILER_NEGATION_H
#define COMPILER_NEGATION_H

#include "UnaryExpression.h"
#include <iostream>

class Negation: public UnaryExpression
{
public:
    Negation(Expression *exp) : UnaryExpression(exp) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_NEGATION_H