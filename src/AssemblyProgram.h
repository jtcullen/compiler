#ifndef COMPILER_ASSEMBLYPROGRAM_H
#define COMPILER_ASSEMBLYPROGRAM_H

#include <iostream>
#include <string>
#include <vector>

class AssemblyProgram
{
private:
    std::vector<std::string> lines;
public:
    void addLine(std::string line);
    friend std::ostream& operator<<(std::ostream& os, const AssemblyProgram& ap);
};

#endif //COMPILER_ASSEMBLYPROGRAM_H