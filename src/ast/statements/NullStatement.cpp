#include "NullStatement.h"

NullStatement::NullStatement() {}

NullStatement::~NullStatement() {}

void NullStatement::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
}

void NullStatement::generate(AssemblyProgram &ap) const {}

std::ostream &operator<<(std::ostream &os, const NullStatement &ret)
{
    os << "Null Statement";

    return os;
}