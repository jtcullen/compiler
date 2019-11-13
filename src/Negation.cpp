#include "Negation.h"

Negation::Negation(Expression *exp) : exp(exp) {}

Negation::~Negation()
{
    delete exp;
}

void Negation::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    exp->print(indent + 1);
}

void Negation::generate(AssemblyProgram &ap)
{
    // Generate code for inner expression first
    exp->generate(ap);

    // Now Negate!
    ap.addLine("    cmp eax, 0"); // Check if eax is 0
    ap.addLine("    mov eax, 0"); // Zero eax, becuase sete only affects one byte
    ap.addLine("    sete al");    // If eax was 0, set to 1, otherwise 0
}

std::ostream &operator<<(std::ostream &os, const Negation &in)
{
    os << "Negation:";

    return os;
}