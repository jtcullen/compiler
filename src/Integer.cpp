#include "Integer.h"

Integer::Integer(int value) : value(value) {}

void Integer::print(int indent)
{
    std::cout << std::string(indent, '-') << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Integer &in)
{
    os << "INTEGER: " << in.value;

    return os;
}