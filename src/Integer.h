#ifndef COMPILER_INTEGER_H
#define COMPILER_INTEGER_H

#include <iostream>

class Integer
{
private:
    int value;
public:
    Integer(int value);
    int getValue();
    void print(int indent);
    friend std::ostream& operator<<(std::ostream& os, const Integer& in);
};

#endif //COMPILER_INTEGER_H