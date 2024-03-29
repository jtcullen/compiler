#include "Program.h"

Program::Program(Function *function) : function(function) {}

Program::~Program()
{
    delete function;
}

void Program::print(std::ostream &os, int indent) const
{
    os << std::string(indent, '-') << *this << std::endl;
    function->print(os, indent + 1);
}

void Program::generate(AssemblyProgram &ap) const
{
    // Add code to call main function
    ap.addLine("global _start");
    ap.addLine("_start:");          // This is the label that linux calls
    ap.addLine("    call _MAIN");   // Call the main function
    ap.addLine("    mov ebx, eax"); // Grab the return value, make param for sys call
    ap.addLine("    mov eax, 1");   // Exit system call
    ap.addLine("    int 0x80");     // Raise an interupt (Call kernel)

    // Generate the code for the rest of the program
    function->generate(ap);
}

std::ostream &operator<<(std::ostream &os, const Program &pr)
{
    os << "PROGRAM";

    return os;
}