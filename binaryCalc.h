#pragma once
#ifndef FUNCTS
#define FUNCTS
#include <string>

class BinaryNum
{
private:
    int number;
    int bits;

public:
    // constructor
    BinaryNum(int dec);

    // arithmetic functions
    void addNum(BinaryNum num);
    void subNum(BinaryNum num);

    // conversion
    int toDecimal();
};

class HexNum
{
private:
    std::string number;
    int digits;

public:
    // arithmetic functions
    void addNum(HexNum num);
    void subNum(HexNum num);

    // conversion
    int toDecimal();
};

#endif