#ifndef COMPILER_RETURN_H
#define COMPILER_RETURN_H

#include <iostream>
#include "Statement.h"
#include "Expression.h"
#include "AssemblyProgram.h"

class Return : public Statement
{
private:
    Expression *exp;

public:
    Return(Expression *exp);
    ~Return();
    void print(std::ostream &os, int indent) const;
    void generate(AssemblyProgram &ap) const;
    friend std::ostream &operator<<(std::ostream &os, const Return &ret);
};

#endif //COMPILER_RETURN_H