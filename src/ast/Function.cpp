#include "Function.h"

Function::Function(std::string name, std::vector<Statement *> body) : name(name), body(body) {}

Function::~Function()
{
    for (std::vector<Statement *>::const_iterator i = body.begin(); i != body.end(); i++)
    {
        delete *i;
    }
}

void Function::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    for (std::vector<Statement *>::const_iterator i = body.begin(); i != body.end(); i++)
    {
        (*i)->print(indent + 1);
    }
}

void Function::generate(AssemblyProgram &ap) const
{
    ap.startScope();

    // Generate function header
    ap.addLine("global _" + name);
    ap.addLine("_" + name + ":");

    // Prologue
    ap.addLine("    push ebp"); // Save the ebp from the last function
    ap.addLine("    mov ebp, esp"); // Set the ebp to the bottom of this function's stack

    // Generate body
    for (std::vector<Statement *>::const_iterator i = body.begin(); i != body.end(); i++)
    {
        (*i)->generate(ap);
    }

    // Epilogue, this is here just in case someone forgets a return statement
    ap.addLine("    mov esp, ebp"); // Restore stack pointer (forget this functions local variables)
    ap.addLine("    pop ebp"); // Restore the base pointer
    ap.addLine("    mov eax, 0"); // Return 0
    ap.addLine("    ret");

    ap.endScope();
}

std::ostream &operator<<(std::ostream &os, const Function &fun)
{
    os << "FUNCTION: " << fun.name;

    return os;
}