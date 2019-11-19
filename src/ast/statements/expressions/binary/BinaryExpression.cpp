#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}

BinaryExpression::~BinaryExpression()
{
    delete left;
    delete right;
}

void BinaryExpression::print(std::ostream &os, int indent) const
{
    os << std::string(indent, '-') << *this << std::endl;
    left->print(os, indent + 1);
    right->print(os, indent + 1);
}

std::ostream &operator<<(std::ostream &os, const BinaryExpression &in)
{
    os << in.getName() << ":";

    return os;
}