#ifndef COMPILER_SUBTRACTION_H
#define COMPILER_SUBTRACTION_H

#include "Expression.h"
#include <iostream>

class Subtraction: public Expression
{
private:
    Expression *left, *right;
public:
    Subtraction(Expression *left, Expression *right);
    ~Subtraction();
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Subtraction& in);
};

#endif //COMPILER_SUBTRACTION_H