#include "And.h"

void And::generate(AssemblyProgram &ap) const
{
    static int count = 0;
    std::string labelNum = std::to_string(++count);

    // Generate code for left first
    left->generate(ap);

    // Check if left is true, jump to right if it is
    ap.addLine("    cmp eax, 0");
    ap.addLine("    jne _andRight" + labelNum);
    ap.addLine("    jmp _andEnd" + labelNum); // Otherwise we can jump to the end

    // Right side
    ap.addLine("_andRight" + labelNum + ":"); // Label to jump to for right
    right->generate(ap);

    ap.addLine("    cmp eax, 0"); // Check if right is false
    ap.addLine("    mov eax, 0"); // Zero out eax
    ap.addLine("    setne al");   // If this was true, set eax to 1

    // Label to jump to if we know the answer
    ap.addLine("_andEnd" + labelNum + ":");
}

std::string And::getName() const
{
    return "And";
}