#include "Multiplication.h"

Multiplication::Multiplication(Expression *left, Expression *right) : left(left), right(right) {}

Multiplication::~Multiplication()
{
    delete left;
    delete right;
}

void Multiplication::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    left->print(indent + 1);
    right->print(indent + 1);
}

void Multiplication::generate(AssemblyProgram &ap)
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

std::ostream &operator<<(std::ostream &os, const Multiplication &in)
{
    os << "Multiplication:";

    return os;
}