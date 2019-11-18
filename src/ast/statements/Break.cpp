#include "Break.h"

Break::Break() {}

Break::~Break() {}

void Break::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
}

void Break::generate(AssemblyProgram &ap) const
{
    // Jump to end of loop
    ap.addLine("    jmp " + ap.getLoopEndLabel());
}

std::ostream &operator<<(std::ostream &os, const Break &ret)
{
    os << "BREAK";

    return os;
}