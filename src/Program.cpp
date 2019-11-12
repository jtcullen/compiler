#include "Program.h"

Program::Program(Function function) : function(function) {}

void Program::print(int indent){
    std::cout << std::string(indent, '-') << *this << std::endl;
    function.print(indent + 1);
}

std::ostream& operator<<(std::ostream& os, const Program& pr){
    os << "PROGRAM";

    return os;
}