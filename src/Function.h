#ifndef COMPILER_FUNCTION_H
#define COMPILER_FUNCTION_H

#include <string>
#include "Return.h"

class Function
{
private:
    std::string name;
    Return body;
public:
    Function(std::string name, Return body);
};

#endif //COMPILER_FUNCTION_H