#include "NotEqual.h"

void NotEqual::generate(AssemblyProgram &ap) const
{
    // Generate code for left first
    left->generate(ap);

    // Now we need to put it somewhere to remember it later
    ap.addLine("    push eax"); // Put the result of 'left' on the stack

    // Now we can generate the code for the right expression
    right->generate(ap);

    // We need to retreive the result of 'left' from the stack
    ap.addLine("    pop ecx"); // Pop 'left' off the stack

    // Now compare!
    ap.addLine("    cmp ecx, eax"); // Check if ecx == eax
    ap.addLine("    mov eax, 0");   // Zero eax, becuase setne only affects one byte
    ap.addLine("    setne al");      // If ecx != eax, set to 1, otherwise 0
}

std::string NotEqual::getName() const
{
    return "Not Equal";
}