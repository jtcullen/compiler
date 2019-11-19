#include "Continue.h"

Continue::Continue() {}

Continue::~Continue() {}

void Continue::print(std::ostream &os, int indent) const
{
    os << std::string(indent, '-') << *this << std::endl;
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