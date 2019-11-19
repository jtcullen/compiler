#include "Integer.h"

Integer::Integer(int value) : value(value) {}

void Integer::print(std::ostream &os, int indent) const
{
    os << std::string(indent, '-') << *this << std::endl;
}

void Integer::generate(AssemblyProgram &ap) const
{
    // Move the integer into a register!
    ap.addLine("    mov eax, " + std::to_string(value));
}

std::ostream &operator<<(std::ostream &os, const Integer &in)
{
    os << "INTEGER: " << in.value;

    return os;
}