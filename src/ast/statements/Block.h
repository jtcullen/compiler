#ifndef COMPILER_BLOCK_H
#define COMPILER_BLOCK_H

#include <string>
#include <iostream>
#include "BlockItem.h"
#include "Statement.h"
#include "AssemblyProgram.h"

class Block: public Statement
{
private:
    std::vector<BlockItem*> body;
public:
    Block(std::vector<BlockItem*>  body);
    ~Block();
    void generate(AssemblyProgram &ap) const;
    void print(int indent) const;
    friend std::ostream& operator<<(std::ostream& os, const Block& block);
};

#endif //COMPILER_BLOCK_H