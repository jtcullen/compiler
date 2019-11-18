#include "AssemblyProgram.h"

void AssemblyProgram::startLoop(std::string start, std::string end)
{
    loopLabels.push(std::make_pair(start, end));
}

void AssemblyProgram::endLoop()
{
    loopLabels.pop();
}

std::string AssemblyProgram::getLoopStartLabel()
{
    if (!loopLabels.empty())
    {
        return loopLabels.top().first;
    }
    else
    {
        throw "No loop is open!";
    }
}

std::string AssemblyProgram::getLoopEndLabel()
{
    if (!loopLabels.empty())
    {
        return loopLabels.top().second;
    }
    else
    {
        throw "No loop is open!";
    }
}

void AssemblyProgram::startScope()
{
    variableOffsetScopes.push(variableOffsetInsertionOrder.size());
}

void AssemblyProgram::endScope()
{
    if (!variableOffsetScopes.empty())
    {
        int curLen = variableOffsetInsertionOrder.size();
        int prevLen = variableOffsetScopes.top();
        variableOffsetScopes.pop();

        if (prevLen > 0)
        {
            for (std::vector<std::string>::const_iterator i = variableOffsetInsertionOrder.begin() + prevLen; i != variableOffsetInsertionOrder.end(); i++)
            {
                variableOffsets.erase(*i);
            }

            variableOffsetInsertionOrder.erase(variableOffsetInsertionOrder.begin() + prevLen, variableOffsetInsertionOrder.end());
        }
        else
        {
            variableOffsets.clear();
            variableOffsetInsertionOrder.clear();
        }

        // Set back the stack pointer when the scope closes so new allocations will be correct
        addLine("    add esp, " + std::to_string(4 * (curLen - prevLen)));
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
            if (variableOffsetInsertionOrder.empty())
            {
                offset = -4;
            }
            else
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

void AssemblyProgram::setMainFlag(bool flag)
{
    mainFlag = flag;
}

bool AssemblyProgram::getMainFlag()
{
    return mainFlag;
}

std::ostream &operator<<(std::ostream &os, const AssemblyProgram &ap)
{
    for (std::vector<std::string>::const_iterator l = ap.lines.begin(); l != ap.lines.end(); l++)
    {
        os << *l << std::endl;
    }

    return os;
}