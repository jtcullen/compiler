#ifndef COMPILER_FUNCTION_H
#define COMPILER_FUNCTION_H

#include <string>
#include <iostream>
#include "BlockItem.h"
#include "ASTNode.h"
#include "AssemblyProgram.h"

class Function: public ASTNode
{
private:
    std::string name;
    std::vector<BlockItem*> body;
public:
    Function(std::string name, std::vector<BlockItem*>  body);
    ~Function();
    void generate(AssemblyProgram &ap) const;
    void print(int indent) const;
    friend std::ostream& operator<<(std::ostream& os, const Function& fun);
};

#endif //COMPILER_FUNCTION_H