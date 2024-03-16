#include <string>
#include "baseCalc.h"
using std::string;

map<string, string> hex2bin {{"0001", "1"}, {"0010","2"}, {"0011", "3"}, {"0100","4"}, {"0101", "5"}, {"0110", "6"}, {"0111", "7"}, {"1000", "8"}, {"1001", "9"}, {"1010", "A"}, {"1011", "B"}, {"1100", "C"}, {"1101", "D"}, {"1110", "E"}, {"1111", "F"}};

// Binary Num definitions here

// constructors
BinaryNum::BinaryNum(string binNum)
{
    this->number = number;
    bits = number.length();
}

BinaryNum::BinaryNum(int dec)
{
    // number = decimalToBinary(dec);
    // bits = number.length();
}

// getters
std::string BinaryNum::getNumber()
{
    return number;
}

int BinaryNum::getBits()
{
    return bits;
}

// setter (only need one because length is derived from number)
void BinaryNum::setNumber(string number)
{
    this->number = number;
    bits = number.length();
}

// arithmetic methods (implement if have time otherwise disregard)
BinaryNum BinaryNum::addNum(BinaryNum toAdd)
{
}

BinaryNum BinaryNum::subNum(BinaryNum toAdd)
{
}

// conversion methods
int BinaryNum::toDecimal()
{
}

HexNum BinaryNum::toHex()
{
}

// HexNum definitions here

// constructors
HexNum::HexNum(string hexNum)
{
    this->number = number;
    digits = number.length();
}

HexNum::HexNum(int dec)
{
    // number = decimalToHex(dec);
    // digits = number.length();
}

// getters
string HexNum::getNumber()
{
    return number;
}

int HexNum::getDigits()
{
    return digits;
}

// setter (only need one because length is derived from number)
void HexNum::setNumber(string number)
{
    this->number = number;
    digits = number.length();
}

// arithmetic methods (implement if have time otherwise disregard)
HexNum HexNum::addNum(HexNum toAdd)
{
}

HexNum HexNum::subNum(HexNum toSub)
{
}

// conversion methods
int HexNum::toDecimal()
{
}

BinaryNum HexNum::toBinary()
{
}
