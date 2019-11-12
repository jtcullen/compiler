#ifndef COMPILER_ASTNODE_H
#define COMPILER_ASTNODE_H

#include <string>

class ASTNode
{
public:
    virtual void print(int indent) = 0;
};

#endif //COMPILER_ASTNODE_H