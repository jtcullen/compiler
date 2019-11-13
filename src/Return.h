#ifndef COMPILER_RETURN_H
#define COMPILER_RETURN_H

#include <iostream>
#include "Expression.h"
#include "AssemblyProgram.h"

class Return
{
private:
    Expression *exp;
public:
    Return(Expression *exp);
    ~Return();
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Return& ret);
};

#endif //COMPILER_RETURN_H