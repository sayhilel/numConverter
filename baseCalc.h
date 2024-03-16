#pragma once
#ifndef FUNCTS
#define FUNCTS
#include <string>
using std::string;

class BinaryNum
{
private:
    string number;
    int bits;

public:
    // constructors
    BinaryNum();
    BinaryNum(string bin);
    BinaryNum(int dec);

    // getters and setters
    string getNumber();
    int getBits();
    void setNumber(string number);

    // arithmetic functions
    BinaryNum addNum(BinaryNum num);
    BinaryNum subNum(BinaryNum num);

    // conversion
    int toDecimal();
    HexNum toHex();
};

class HexNum
{
private:
    string number;
    int digits;

public:
    // constructors
    HexNum();
    HexNum(string hex);
    HexNum(int dec);

    // getters and setters
    string getNumber();
    int getDigits();
    void setNumber(string number);

    // arithmetic functions
    HexNum addNum(HexNum num);
    HexNum subNum(HexNum num);

    // conversion
    int toDecimal();
    BinaryNum toBinary();
};

#endif
