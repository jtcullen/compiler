#include "Division.h"

Division::Division(Expression *left, Expression *right) : left(left), right(right) {}

Division::~Division()
{
    delete left;
    delete right;
}

void Division::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    left->print(indent + 1);
    right->print(indent + 1);
}

void Division::generate(AssemblyProgram &ap)
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

std::ostream &operator<<(std::ostream &os, const Division &in)
{
    os << "Division:";

    return os;
}