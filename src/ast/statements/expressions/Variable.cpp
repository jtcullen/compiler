#include "Variable.h"

Variable::Variable(std::string identifier) : identifier(identifier) {}

void Variable::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
}

void Variable::generate(AssemblyProgram &ap) const
{
    int offset = ap.getVariableOffset(identifier);

    // Grab the value at the offset and put it in eax
    ap.addLine("    mov eax, [ebp+" + std::to_string(offset) + "]");
}

std::ostream &operator<<(std::ostream &os, const Variable &in)
{
    os << "Variable: " << in.identifier;

    return os;
}