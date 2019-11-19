#include "NullStatement.h"

NullStatement::NullStatement() {}

NullStatement::~NullStatement() {}

void NullStatement::print(std::ostream &os, int indent) const
{
    os << std::string(indent, '-') << *this << std::endl;
}

void NullStatement::generate(AssemblyProgram &ap) const {}

std::ostream &operator<<(std::ostream &os, const NullStatement &ret)
{
    os << "Null Statement";

    return os;
}