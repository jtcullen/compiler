#include "Return.h"

Return::Return(Expression *exp) : exp(exp) {}

Return::~Return()
{
    delete exp;
}

void Return::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    exp->print(indent + 1);
}

void Return::generate(AssemblyProgram &ap)
{
    // Generate code for expression first
    exp->generate(ap);

    // Now we can return
    ap.addLine("    ret");
}

std::ostream &operator<<(std::ostream &os, const Return &ret)
{
    os << "RETURN";

    return os;
}