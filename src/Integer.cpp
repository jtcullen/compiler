#include "Integer.h"

Integer::Integer(int value) : value(value) {}

void Integer::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
}

void Integer::generate(AssemblyProgram &ap)
{
    // Move the integer into a register!
    ap.addLine("    mov eax, " + std::to_string(value));
}

std::ostream &operator<<(std::ostream &os, const Integer &in)
{
    os << "INTEGER: " << in.value;

    return os;
}