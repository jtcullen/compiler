#ifndef COMPILER_RETURN_H
#define COMPILER_RETURN_H

#include <iostream>
#include "Integer.h"
#include "AssemblyProgram.h"

class Return
{
private:
    Integer integer;
public:
    Return(Integer integer);
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Return& ret);
};

#endif //COMPILER_RETURN_H