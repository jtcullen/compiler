#ifndef COMPILER_UNARYEXPRESSION_H
#define COMPILER_UNARYEXPRESSION_H

#include "Expression.h"
#include <iostream>

class UnaryExpression: public Expression
{
protected:
    Expression *exp;
public:
    UnaryExpression(Expression *exp);
    ~UnaryExpression();
    void print(int indent) const;
    virtual std::string getName() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const UnaryExpression& in);
};

#endif //COMPILER_UNARYEXPRESSION_H