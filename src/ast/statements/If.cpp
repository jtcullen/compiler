#include "If.h"

If::If(Expression *exp, Statement *ifStatement, Statement *elseStatement) : exp(exp), ifStatement(ifStatement), elseStatement(elseStatement) {}

If::~If()
{
    delete exp;
    delete ifStatement;
    delete elseStatement;
}

void If::print(std::ostream &os, int indent) const
{
    os << std::string(indent, '-') << *this << std::endl;
    exp->print(os, indent + 1);
    ifStatement->print(os, indent + 1);

    if (elseStatement != nullptr)
    {
        elseStatement->print(os, indent + 1);
    }
}

void If::generate(AssemblyProgram &ap) const
{
    static int count = 0;
    std::string labelNum = std::to_string(++count);

    // Generate code for expression
    exp->generate(ap);

    // Now check if its 0 (false)
    ap.addLine("    cmp eax, 0");
    ap.addLine("    je _else" + labelNum); // Jump to else if it was false

    // Now we can generate code for the if statement
    ifStatement->generate(ap);
    ap.addLine("    jmp _elseEnd" + labelNum); // Jump over else code so we dont accidentally execute it

    // Section for else statement
    ap.addLine("_else" + labelNum + ":");
    if(elseStatement != nullptr){
        elseStatement->generate(ap);
    }

    // End of the if statement
    ap.addLine("_elseEnd" + labelNum + ":");
}

std::ostream &operator<<(std::ostream &os, const If &ret)
{
    os << "IF";

    return os;
}