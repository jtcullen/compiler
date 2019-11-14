#include "Negative.h"

void Negative::generate(AssemblyProgram &ap) const
{
    // Generate code for inner expression first
    exp->generate(ap);

    // Now flip the sign!
    ap.addLine("    neg eax");
}

std::string Negative::getName() const
{
    return "Negative";
}