#ifndef COMPILER_FUNCTION_H
#define COMPILER_FUNCTION_H

#include <string>
#include <iostream>
#include "Return.h"
#include "AssemblyProgram.h"

class Function
{
private:
    std::string name;
    Return body;
public:
    Function(std::string name, Return body);
    void generate(AssemblyProgram &ap);
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Function& fun);
};

#endif //COMPILER_FUNCTION_H