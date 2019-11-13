#ifndef COMPILER_COMPLEMENT_H
#define COMPILER_COMPLEMENT_H

#include "Expression.h"
#include <iostream>

class Complement: public Expression
{
private:
    Expression *exp;
public:
    Complement(Expression *exp);
    ~Complement();
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Complement& in);
};

#endif //COMPILER_COMPLEMENT_H