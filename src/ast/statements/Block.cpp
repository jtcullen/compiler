#include "Block.h"

Block::Block(std::vector<BlockItem *> body) : body(body) {}

Block::~Block()
{
    for (std::vector<BlockItem *>::const_iterator i = body.begin(); i != body.end(); i++)
    {
        delete *i;
    }
}

void Block::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    for (std::vector<BlockItem *>::const_iterator i = body.begin(); i != body.end(); i++)
    {
        (*i)->print(indent + 1);
    }
}

void Block::generate(AssemblyProgram &ap) const
{
    ap.startScope();

    // Generate body
    for (std::vector<BlockItem *>::const_iterator i = body.begin(); i != body.end(); i++)
    {
        (*i)->generate(ap);
    }

    ap.endScope();
}

std::ostream &operator<<(std::ostream &os, const Block &fun)
{
    os << "Block: ";

    return os;
}