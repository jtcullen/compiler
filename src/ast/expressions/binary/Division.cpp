#include "Division.h"

void Division::generate(AssemblyProgram &ap) const
{
    // Generate code for right expression first
    right->generate(ap);

    // Now we need to put it somewhere to remember it later
    ap.addLine("    push eax"); // Put the result of 'right' on the stack

    // Now we can generate the code for the left expression
    left->generate(ap);

    // We need to sign extend it to divide
    ap.addLine("    cdq");

    // We need to retreive the result of 'right' from the stack
    ap.addLine("    pop ecx"); // Pop 'right' off the stack

    // Now we can divide edx:eax (implicit) by ecx
    ap.addLine("    idiv ecx");
}

std::string Division::getName() const
{
    return "Division";
}