#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(Expression *exp) : exp(exp) {}

UnaryExpression::~UnaryExpression()
{
    delete exp;
}

void UnaryExpression::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    exp->print(indent + 1);
}

std::ostream &operator<<(std::ostream &os, const UnaryExpression &in)
{
    os << in.getName() << ":";

    return os;
}