#include "AssemblyProgram.h"

void AssemblyProgram::startScope()
{
    variableOffsetScopes.push(variableOffsetInsertionOrder.size());
}

void AssemblyProgram::endScope()
{
    if (!variableOffsetScopes.empty())
    {
        int prevLen = variableOffsetScopes.top();
        variableOffsetScopes.pop();

        if (prevLen > 0)
        {
            for (std::vector<std::string>::const_iterator i = variableOffsetInsertionOrder.begin() + prevLen - 1; i != variableOffsetInsertionOrder.end(); i++)
            {
                variableOffsets.erase(*i);
            }

            variableOffsetInsertionOrder.erase(variableOffsetInsertionOrder.begin() + prevLen - 1, variableOffsetInsertionOrder.end());
        }
        else
        {
            variableOffsets.clear();
            variableOffsetInsertionOrder.clear();
        }
    }
    else
    {
        throw "No scope is open!";
    }
}

void AssemblyProgram::addVariableToScope(std::string identifier)
{
    if (!variableOffsetScopes.empty())
    {
        if (variableOffsets.find(identifier) == variableOffsets.end())
        {
            int offset;
            if(variableOffsetInsertionOrder.empty()){
                offset = -4;
            }else
            {
                std::map<std::string, int>::iterator it = variableOffsets.find(variableOffsetInsertionOrder.back());
                offset = it->second - 4;
            }
            
            variableOffsets.insert({identifier, offset});
            variableOffsetInsertionOrder.push_back(identifier);
        }
        else
        {
            throw "Variable already exists in scope!";
        }
    }
    else
    {
        throw "No scope is open!";
    }
}

int AssemblyProgram::getVariableOffset(std::string identifier)
{
    std::map<std::string, int>::iterator it = variableOffsets.find(identifier);

    if (it != variableOffsets.end())
    {
        return it->second;
    }

    throw "Variable not in scope!";
}

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