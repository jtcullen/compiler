#include "Declaration.h"

Declaration::Declaration(std::string identifier, Expression *exp) : identifier(identifier), exp(exp) {}

void Declaration::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    exp->print(indent + 1);
}

void Declaration::generate(AssemblyProgram &ap) const
{
    ap.addVariableToScope(identifier);
}

std::ostream &operator<<(std::ostream &os, const Declaration &in)
{
    os << "Declaration: " + in.identifier;

    return os;
}