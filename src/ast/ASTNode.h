#ifndef COMPILER_ASTNODE_H
#define COMPILER_ASTNODE_H

#include "AssemblyProgram.h"

class ASTNode
{
public:
    virtual ~ASTNode() {};
    virtual void generate(AssemblyProgram &ap) const = 0;
    virtual void print(int indent) const = 0;
};

#endif //COMPILER_ASTNODE_H