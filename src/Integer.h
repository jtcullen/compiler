#ifndef COMPILER_INTEGER_H
#define COMPILER_INTEGER_H

#include <iostream>
#include "ASTNode.h"

class Integer: public ASTNode
{
private:
    int value;
public:
    Integer(int value);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Integer& in);
};

#endif //COMPILER_INTEGER_H