#include "For.h"

For::For(Expression *assign, Expression *control, Expression *inc, Statement *body) : assign(assign), control(control), inc(inc), body(body) {}

For::~For()
{
    delete assign;
    delete control;
    delete inc;
    delete body;
}

void For::print(int indent) const
{
    std::cout << std::string(indent, '-') << *this << std::endl;

    if (assign != nullptr)
    {
        assign->print(indent + 1);
    }

    if (control != nullptr)
    {
        control->print(indent + 1);
    }

    if (inc != nullptr)
    {
        inc->print(indent + 1);
    }

    body->print(indent + 1);
}

void For::generate(AssemblyProgram &ap) const
{
    static int count = 0;
    std::string labelNum = std::to_string(++count);

    std::string startLabel = "_forBegin" + labelNum;
    std::string endLabel = "_forEnd" + labelNum;

    ap.startLoop(startLabel, endLabel);

    // Generate Assign
    if (assign != nullptr)
    {
        assign->generate(ap);
    }

    // Label the beginning of the loop
    ap.addLine(startLabel + ":");

    // Generate control, if its not present we will just consider it to be true
    if (control != nullptr)
    {
        control->generate(ap);
    }
    else
    {
        ap.addLine("    mov eax, 1");
    }

    // Now check if its 0 (false)
    ap.addLine("    cmp eax, 0");
    ap.addLine("    je " + endLabel); // Jump to end if it was false

    // Now we can generate the body
    body->generate(ap);

    // And the increment
    if (inc != nullptr)
    {
        inc->generate(ap);
    }

    // And jump back to the beginning of the loop
    ap.addLine("    jmp " + startLabel);

    // End of the loop
    ap.addLine(endLabel + ":");

    ap.endLoop();
}

std::ostream &operator<<(std::ostream &os, const For &ret)
{
    os << "FOR";

    return os;
}