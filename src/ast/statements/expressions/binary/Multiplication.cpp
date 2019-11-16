#include "Multiplication.h"

void Multiplication::generate(AssemblyProgram &ap) const
{
    // Generate code for left expression first
    left->generate(ap);

    // Now we need to put it somewhere to remember it later
    ap.addLine("    push eax"); // Put the result of 'left' on the stack

    // Now we can generate the code for the right expression
    right->generate(ap);

    // We need to retreive the result of 'left' from the stack
    ap.addLine("    pop ecx"); // Pop 'left' off the stack

    // Now we can multiply 'left' and 'right'
    ap.addLine("    imul eax, ecx");
}

std::string Multiplication::getName() const
{
    return "Multiplication";
}