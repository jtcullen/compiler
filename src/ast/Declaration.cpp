#include "Declaration.h"

Declaration::Declaration(std::string identifier, Expression *exp) : identifier(identifier), exp(exp) {}

void Declaration::print(std::ostream &os, int indent) const
{
    os << std::string(indent, '-') << *this << std::endl;
    if (exp != nullptr)
        exp->print(os, indent + 1);
}

void Declaration::generate(AssemblyProgram &ap) const
{
    if (exp != nullptr)
    {
        exp->generate(ap); // We will initilize the variable to this expression
    }
    else
    {
        ap.addLine("    mov eax, 0"); // Init to zero if there is no expression
    }
    
    ap.addLine("    push eax"); // Put the variable on the stack
    ap.addVariableToScope(identifier); // Remember that this is declared in the current scope
}

std::ostream &operator<<(std::ostream &os, const Declaration &in)
{
    os << "Declaration: " + in.identifier;

    return os;
}