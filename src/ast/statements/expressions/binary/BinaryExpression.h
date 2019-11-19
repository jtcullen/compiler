#ifndef COMPILER_BINARYEXPRESSION_H
#define COMPILER_BINARYEXPRESSION_H

#include "Expression.h"
#include <iostream>

class BinaryExpression: public Expression
{
protected:
    Expression *left, *right;
public:
    BinaryExpression(Expression *left, Expression *right);
    ~BinaryExpression();
    void print(std::ostream &os, int indent) const;
    virtual std::string getName() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const BinaryExpression& in);
};

#endif //COMPILER_BINARYEXPRESSION_H