#ifndef COMPILER_MULTIPLICATION_H
#define COMPILER_MULTIPLICATION_H

#include "Expression.h"
#include <iostream>

class Multiplication: public Expression
{
private:
    Expression *left, *right;
public:
    Multiplication(Expression *left, Expression *right);
    ~Multiplication();
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Multiplication& in);
};

#endif //COMPILER_MULTIPLICATION_H