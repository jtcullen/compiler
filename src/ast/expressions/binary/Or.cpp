#include "Or.h"

void Or::generate(AssemblyProgram &ap) const
{
    static int count = 0;
    std::string labelNum = std::to_string(++count);

    // Generate code for left first
    left->generate(ap);

    // Check if left is false, jump to right if it is
    ap.addLine("    cmp eax, 0");
    ap.addLine("    je _orRight" + labelNum);
    ap.addLine("    mov eax, 1"); // Otherwise this statement is true
    ap.addLine("    jmp _orEnd" + labelNum); // We can jump to the end

    // Right side
    ap.addLine("_orRight" + labelNum + ":"); // Label to jump to for right
    right->generate(ap);

    ap.addLine("    cmp eax, 0"); // Check if right is false
    ap.addLine("    mov eax, 0"); // Zero out eax
    ap.addLine("    setne al"); // If this was true, set eax to 1

    // Label to jump to if we know the answer
    ap.addLine("_orEnd" + labelNum + ":");
}

std::string Or::getName() const
{
    return "Or";
}