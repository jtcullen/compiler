#ifndef COMPILER_DECLARATION_H
#define COMPILER_DECLARATION_H

#include "Expression.h"
#include "BlockItem.h"
#include <iostream>

class Declaration: public BlockItem
{
private:
    std::string identifier;
    Expression *exp;
public:
    Declaration(std::string identifier, Expression *exp);
    void generate(AssemblyProgram &ap) const;
    void print(std::ostream &os, int indent) const;
    friend std::ostream& operator<<(std::ostream& os, const Declaration& in);
};

#endif //COMPILER_DECLARATION_H