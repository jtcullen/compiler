#ifndef COMPILER_INTEGER_H
#define COMPILER_INTEGER_H

#include "Expression.h"
#include <iostream>

class Integer: public Expression
{
private:
    int value;
public:
    Integer(int value);
    void generate(AssemblyProgram &ap) const;
    void print(int indent) const;
    friend std::ostream& operator<<(std::ostream& os, const Integer& in);
};

#endif //COMPILER_INTEGER_H