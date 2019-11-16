#ifndef COMPILER_ASSEMBLYPROGRAM_H
#define COMPILER_ASSEMBLYPROGRAM_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

class AssemblyProgram
{
private:
    std::map<std::string, int> variableOffsets;
    std::vector<std::string> variableOffsetInsertionOrder;
    std::stack<int> variableOffsetScopes;
    std::vector<std::string> lines;
public:
    void startScope();
    void endScope();
    void addVariableToScope(std::string identifier);
    int getVariableOffset(std::string identifier);
    void addLine(std::string line);
    friend std::ostream& operator<<(std::ostream& os, const AssemblyProgram& ap);
};

#endif //COMPILER_ASSEMBLYPROGRAM_H