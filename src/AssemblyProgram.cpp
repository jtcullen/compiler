#include "AssemblyProgram.h"

void AssemblyProgram::addLine(std::string line)
{
    lines.push_back(line);
}

std::ostream &operator<<(std::ostream &os, const AssemblyProgram &ap)
{
    for (std::vector<std::string>::const_iterator l = ap.lines.begin(); l != ap.lines.end(); l++)
    {
        os << *l << std::endl;
    }
    
    return os;
}