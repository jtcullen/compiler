#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(Expression *exp) : exp(exp) {}

UnaryExpression::~UnaryExpression()
{
    delete exp;
}

void UnaryExpression::print(std::ostream &os, int indent) const
{
    os << std::string(indent, '-') << *this << std::endl;
    exp->print(os, indent + 1);
}

std::ostream &operator<<(std::ostream &os, const UnaryExpression &in)
{
    os << in.getName() << ":";

    return os;
}