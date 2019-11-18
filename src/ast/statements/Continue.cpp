#include "Continue.h"

Continue::Continue() {}

Continue::~Continue() {}

void Continue::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
}

void Continue::generate(AssemblyProgram &ap) const
{
    // Jump to start of loop
    ap.addLine("    jmp " + ap.getLoopStartLabel());
}

std::ostream &operator<<(std::ostream &os, const Continue &ret)
{
    os << "CONTINUE";

    return os;
}