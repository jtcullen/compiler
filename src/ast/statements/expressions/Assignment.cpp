#include "Assignment.h"

Assignment::Assignment(std::string identifier, Expression *exp) : identifier(identifier), exp(exp) {}

void Assignment::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    exp->print(indent + 1);
}

void Assignment::generate(AssemblyProgram &ap) const
{
    int offset = ap.getVariableOffset(identifier);

    // Evaluate expression
    exp->generate(ap);

    // Save the new value on the stack
    ap.addLine("    mov [ebp+" + std::to_string(offset) + "], eax");
}

std::ostream &operator<<(std::ostream &os, const Assignment &in)
{
    os << "Assignment: " + in.identifier;

    return os;
}