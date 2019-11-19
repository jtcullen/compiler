#ifndef COMPILER_WHILE_H
#define COMPILER_WHILE_H

#include <iostream>
#include "Statement.h"
#include "Expression.h"
#include "AssemblyProgram.h"

class While : public Statement
{
private:
    Expression *exp;
    Statement *body;
public:
    While(Expression *exp, Statement *body);
    ~While();
    void print(std::ostream &os, int indent) const;
    void generate(AssemblyProgram &ap) const;
    friend std::ostream &operator<<(std::ostream &os, const While &ret);
};

#endif //COMPILER_WHILE_H