#ifndef COMPILER_DECLARATION_H
#define COMPILER_DECLARATION_H

#include "Expression.h"
#include "Statement.h"
#include <iostream>

class Declaration: public Statement
{
private:
    std::string identifier;
    Expression *exp;
public:
    Declaration(std::string identifier, Expression *exp);
    void generate(AssemblyProgram &ap) const;
    void print(int indent) const;
    friend std::ostream& operator<<(std::ostream& os, const Declaration& in);
};

#endif //COMPILER_DECLARATION_H