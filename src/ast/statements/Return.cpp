#include "Return.h"

Return::Return(Expression *exp) : exp(exp) {}

Return::~Return()
{
    delete exp;
}

void Return::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    exp->print(indent + 1);
}

void Return::generate(AssemblyProgram &ap) const
{
    // Generate code for expression first
    exp->generate(ap);

    // Clean up our scope
    ap.addLine("    mov esp, ebp"); // Restore stack pointer (forget this functions local variables)
    ap.addLine("    pop ebp");      // Restore the base pointer

    // Now we can return
    ap.addLine("    ret");
}

std::ostream &operator<<(std::ostream &os, const Return &ret)
{
    os << "RETURN";

    return os;
}