#ifndef COMPILER_ADDITION_H
#define COMPILER_ADDITION_H

#include "Expression.h"
#include <iostream>

class Addition: public Expression
{
private:
    Expression *left, *right;
public:
    Addition(Expression *left, Expression *right);
    ~Addition();
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Addition& in);
};

#endif //COMPILER_ADDITION_H