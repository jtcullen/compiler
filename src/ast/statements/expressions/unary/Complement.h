#ifndef COMPILER_COMPLEMENT_H
#define COMPILER_COMPLEMENT_H

#include "UnaryExpression.h"
#include <iostream>

class Complement: public UnaryExpression
{
public:
    Complement(Expression *exp) : UnaryExpression(exp) {}
    void generate(AssemblyProgram &ap) const;
    std::string getName() const;
};

#endif //COMPILER_COMPLEMENT_H