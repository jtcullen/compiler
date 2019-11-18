#ifndef COMPILER_FOR_H
#define COMPILER_FOR_H

#include <iostream>
#include "Statement.h"
#include "Expression.h"
#include "AssemblyProgram.h"

class For : public Statement
{
private:
    Expression *assign, *control, *inc;
    Statement *body;
public:
    For(Expression *assign, Expression *control, Expression *inc, Statement *body);
    ~For();
    void print(int indent) const;
    void generate(AssemblyProgram &ap) const;
    friend std::ostream &operator<<(std::ostream &os, const For &ret);
};

#endif //COMPILER_FOR_H