#include "Subtraction.h"

Subtraction::Subtraction(Expression *left, Expression *right) : left(left), right(right) {}

Subtraction::~Subtraction()
{
    delete left;
    delete right;
}

void Subtraction::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    left->print(indent + 1);
    right->print(indent + 1);
}

void Subtraction::generate(AssemblyProgram &ap)
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

std::ostream &operator<<(std::ostream &os, const Subtraction &in)
{
    os << "Subtraction:";

    return os;
}