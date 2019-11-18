#include "While.h"

While::While(Expression *exp, Statement *body) : exp(exp), body(body) {}

While::~While()
{
    delete exp;
    delete body;
}

void While::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;
    exp->print(indent + 1);
    body->print(indent + 1);
}

void While::generate(AssemblyProgram &ap) const
{
    static int count = 0;
    std::string labelNum = std::to_string(++count);

    std::string startLabel = "_whileBegin" + labelNum;
    std::string endLabel = "_whileEnd" + labelNum;

    ap.startLoop(startLabel, endLabel);

    // Label the beginning of the loop
    ap.addLine(startLabel + ":");

    // Generate code for expression
    exp->generate(ap);

    // Now check if its 0 (false)
    ap.addLine("    cmp eax, 0");
    ap.addLine("    je " + endLabel); // Jump to end if it was false

    // Now we can generate the body
    body->generate(ap);

    // And jump back to the beginning of the loop
    ap.addLine("    jmp " + startLabel);

    // End of the loop
    ap.addLine(endLabel + ":");

    ap.endLoop();
}

std::ostream &operator<<(std::ostream &os, const While &ret)
{
    os << "WHILE";

    return os;
}