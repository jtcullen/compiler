#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include "Function.h"

class Program
{
private:
    Function function;
public:
    Program(Function function);
};

#endif //COMPILER_PROGRAM_H