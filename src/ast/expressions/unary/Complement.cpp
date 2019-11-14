#include "Complement.h"

void Complement::generate(AssemblyProgram &ap) const
{
    // Generate code for inner expression first
    exp->generate(ap);

    // Now flip the bits!
    ap.addLine("    not eax");
}

std::string Complement::getName() const
{
    return "Complement";
}