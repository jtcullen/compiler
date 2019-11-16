#ifndef COMPILER_ASSIGNMENT_H
#define COMPILER_ASSIGNMENT_H

#include "Expression.h"
#include <iostream>

class Assignment: public Expression
{
private:
    std::string identifier;
    Expression *exp;
public:
    Assignment(std::string identifier, Expression *exp);
    void generate(AssemblyProgram &ap) const;
    void print(int indent) const;
    friend std::ostream& operator<<(std::ostream& os, const Assignment& in);
};

#endif //COMPILER_ASSIGNMENT_H