#include "Subtraction.h"

void Subtraction::generate(AssemblyProgram &ap) const
{
    // Generate code for right expression first
    right->generate(ap);

    // Now we need to put it somewhere to remember it later
    ap.addLine("    push eax"); // Put the result of 'right' on the stack

    // Now we can generate the code for the left expression
    left->generate(ap);

    // We need to retreive the result of 'right' from the stack
    ap.addLine("    pop ecx"); // Pop 'right' off the stack

    // Now we can remove 'right' (ecx) from 'left' (eax)
    ap.addLine("    sub eax, ecx");
}

std::string Subtraction::getName() const
{
    return "Subtraction";
}