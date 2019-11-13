#include "Complement.h"

Complement::Complement(Expression *exp) : exp(exp) {}

Complement::~Complement()
{
    delete exp;
}

void Complement::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    exp->print(indent + 1);
}

void Complement::generate(AssemblyProgram &ap)
{
    // Generate code for inner expression first
    exp->generate(ap);

    // Now flip the bits!
    ap.addLine("    not eax");
}

std::ostream &operator<<(std::ostream &os, const Complement &in)
{
    os << "Complement:";

    return os;
}