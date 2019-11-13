#include "Function.h"

Function::Function(std::string name, Return *body) : name(name), body(body) {}

Function::~Function()
{
    delete body;
}

void Function::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    body->print(indent + 1);
}

void Function::generate(AssemblyProgram &ap)
{
    // Generate function header
    ap.addLine("global _" + name);
    ap.addLine("_" + name + ":");

    // Generate body
    body->generate(ap);
}

std::ostream &operator<<(std::ostream &os, const Function &fun)
{
    os << "FUNCTION: " << fun.name;

    return os;
}