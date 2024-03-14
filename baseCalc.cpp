#include <string>
#include "baseCalc.h"
using std::string;

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
std::string HexNum::getNumber()
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