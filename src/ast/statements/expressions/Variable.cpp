#include "Variable.h"

Variable::Variable(std::string identifier) : identifier(identifier) {}

void Variable::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
}

void Variable::generate(AssemblyProgram &ap) const
{

}

std::ostream &operator<<(std::ostream &os, const Variable &in)
{
    os << "Variable: " << in.identifier;

    return os;
}