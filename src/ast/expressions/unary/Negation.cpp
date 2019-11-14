#include "Negation.h"

void Negation::generate(AssemblyProgram &ap) const
{
    // Generate code for inner expression first
    exp->generate(ap);

    // Now Negate!
    ap.addLine("    cmp eax, 0"); // Check if eax is 0
    ap.addLine("    mov eax, 0"); // Zero eax, becuase sete only affects one byte
    ap.addLine("    sete al");    // If eax was 0, set to 1, otherwise 0
}

std::string Negation::getName() const
{
    return "Negation";
}