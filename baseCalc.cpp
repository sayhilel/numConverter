#include "baseCalc.h"
#include "util.hpp"
#include <string>
using std::string;
// Binary Num definitions here
// constructors
BinaryNum::BinaryNum(string binNum) {
  this->number = "0b" + binNum;
  bits = number.length();
}

BinaryNum::BinaryNum(int dec) {
  number = dec2Bin(dec);
  bits = number.length();
}

// getters
std::string BinaryNum::getNumber() { return number; }

int BinaryNum::getBits() { return bits; }

// setter (only need one because length is derived from number)
void BinaryNum::setNumber(string number) {
  this->number = number;
  bits = number.length();
}

// arithmetic methods (implement if have time otherwise disregard)
BinaryNum BinaryNum::addNum(BinaryNum toAdd) {}

BinaryNum BinaryNum::subNum(BinaryNum toAdd) {}

// conversion methods
int BinaryNum::toDecimal() { return bin2Dec(number); }

HexNum *BinaryNum::toHex() { return new HexNum(bin2Hex(number, bits)); }

// HexNum definitions here

// constructors
HexNum::HexNum(string hexNum) {
  this->number = hexNum;
  digits = number.length();
}

HexNum::HexNum(int dec) {
  string bin = dec2Bin(dec);
  number = bin2Hex(bin, bin.length());
  digits = number.length();
}

// getters
string HexNum::getNumber() { return number; }

int HexNum::getDigits() { return digits; }

// setter (only need one because length is derived from number)
void HexNum::setNumber(string number) {
  this->number = number;
  digits = number.length();
}

// arithmetic methods (implement if have time otherwise disregard)
HexNum HexNum::addNum(HexNum toAdd) {}

HexNum HexNum::subNum(HexNum toSub) {}

// conversion methods
int HexNum::toDecimal() {
  int result = 0;
  string bin = hex2Bin(number);
  return bin2Dec(bin);
}

BinaryNum *HexNum::toBinary() { return new BinaryNum(hex2Bin(number)); }
