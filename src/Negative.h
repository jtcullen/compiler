#ifndef COMPILER_NEGATIVE_H
#define COMPILER_NEGATIVE_H

#include "Expression.h"
#include <iostream>

class Negative: public Expression
{
private:
    Expression *exp;
public:
    Negative(Expression *exp);
    ~Negative();
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Negative& in);
};

#endif //COMPILER_NEGATIVE_H