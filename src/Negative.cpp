#include "Negative.h"

Negative::Negative(Expression *exp) : exp(exp) {}

Negative::~Negative()
{
    delete exp;
}

void Negative::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    exp->print(indent + 1);
}

void Negative::generate(AssemblyProgram &ap)
{
    // Generate code for inner expression first
    exp->generate(ap);

    // Now flip the sign!
    ap.addLine("    neg eax");
}

std::ostream &operator<<(std::ostream &os, const Negative &in)
{
    os << "Negative:";

    return os;
}