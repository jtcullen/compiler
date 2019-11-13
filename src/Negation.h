#ifndef COMPILER_NEGATION_H
#define COMPILER_NEGATION_H

#include "Expression.h"
#include <iostream>

class Negation: public Expression
{
private:
    Expression *exp;
public:
    Negation(Expression *exp);
    ~Negation();
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Negation& in);
};

#endif //COMPILER_NEGATION_H