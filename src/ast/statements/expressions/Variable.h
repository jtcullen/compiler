#ifndef COMPILER_VARIABLE_H
#define COMPILER_VARIABLE_H

#include "Expression.h"
#include <iostream>

class Variable: public Expression
{
private:
    std::string identifier;
public:
    Variable(std::string identifier);
    void generate(AssemblyProgram &ap) const;
    void print(std::ostream &os, int indent) const;
    friend std::ostream& operator<<(std::ostream& os, const Variable& in);
};

#endif //COMPILER_VARIABLE_H