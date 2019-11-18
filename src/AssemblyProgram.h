#ifndef COMPILER_ASSEMBLYPROGRAM_H
#define COMPILER_ASSEMBLYPROGRAM_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <utility>

class AssemblyProgram
{
private:
    std::map<std::string, int> variableOffsets;
    std::vector<std::string> variableOffsetInsertionOrder;
    std::stack<int> variableOffsetScopes;
    std::vector<std::string> lines;
    std::stack<std::pair<std::string, std::string>> loopLabels;
    bool mainFlag;
public:
    void setMainFlag(bool flag);
    bool getMainFlag();
    void startLoop(std::string start, std::string end);
    void endLoop();
    std::string getLoopStartLabel();
    std::string getLoopEndLabel();
    void startScope();
    void endScope();
    void addVariableToScope(std::string identifier);
    int getVariableOffset(std::string identifier);
    void addLine(std::string line);
    friend std::ostream &operator<<(std::ostream &os, const AssemblyProgram &ap);
};

#endif //COMPILER_ASSEMBLYPROGRAM_H
