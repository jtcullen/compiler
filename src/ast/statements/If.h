#ifndef COMPILER_IF_H
#define COMPILER_IF_H

#include <iostream>
#include "Statement.h"
#include "Expression.h"
#include "AssemblyProgram.h"

class If : public Statement
{
private:
    Expression *exp;
    Statement *ifStatement, *elseStatement;
public:
    If(Expression *exp, Statement *ifStatement, Statement *elseStatement);
    ~If();
    void print(int indent) const;
    void generate(AssemblyProgram &ap) const;
    friend std::ostream &operator<<(std::ostream &os, const If &ret);
};

#endif //COMPILER_IF_H