#include "Function.h"

Function::Function(std::string name, Return body) : name(name), body(body) {}

void Function::print(int indent){
    std::cout << std::string(indent, '-') << *this << std::endl;
    body.print(indent + 1);
}

std::ostream& operator<<(std::ostream& os, const Function& fun){
    os << "FUNCTION: " << fun.name;

    return os;
}