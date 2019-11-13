#include "Return.h"

Return::Return(Integer integer) : integer(integer) {}

void Return::print(int indent){
    std::cout << std::string(indent, '-') << *this << std::endl;
    integer.print(indent + 1);
}

void Return::generate(AssemblyProgram &ap)
{
    ap.addLine("    mov eax, " + std::to_string(integer.getValue()));
    ap.addLine("    ret");
}

std::ostream& operator<<(std::ostream& os, const Return& ret){
    os << "RETURN";

    return os;
}