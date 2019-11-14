#include "Addition.h"

void Addition::generate(AssemblyProgram &ap) const
{
    // Generate code for left expression first
    left->generate(ap);

    // Now we need to put it somewhere to remember it later
    ap.addLine("    push eax"); // Put the result of 'left' on the stack

    // Now we can generate the code for the right expression
    right->generate(ap);

    // We need to retreive the result of 'left' from the stack
    ap.addLine("    pop ecx"); // Pop 'left' off the stack

    // Now we can add 'left' to 'right'
    ap.addLine("    add eax, ecx");
}

std::string Addition::getName() const
{
    return "Addition";
}