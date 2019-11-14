#ifndef COMPILER_DIVISION_H
#define COMPILER_DIVISION_H

#include "Expression.h"
#include <iostream>

class Division: public Expression
{
private:
    Expression *left, *right;
public:
    Division(Expression *left, Expression *right);
    ~Division();
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Division& in);
};

#endif //COMPILER_DIVISION_H