#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}

BinaryExpression::~BinaryExpression()
{
    delete left;
    delete right;
}

void BinaryExpression::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    left->print(indent + 1);
    right->print(indent + 1);
}

std::ostream &operator<<(std::ostream &os, const BinaryExpression &in)
{
    os << in.getName() << ":";

    return os;
}