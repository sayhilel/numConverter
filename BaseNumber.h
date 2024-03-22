#pragma once
#ifndef MODELPROGRAM_BASENUMBER_H
#define MODELPROGRAM_BASENUMBER_H

#include "util.hpp"
#include <cmath>
#include <map>
#include <string>

using namespace std;

class BaseNumber {
private:
  string value; // The numeric value in string representation
  string type;  // The base type ("0b", "0d", "0x")

  // Conversion methods
  void toDecimal();

  void toBinary();

  void toHex();

public:
  // Constructors
  BaseNumber(); // Default constructor if needed
  BaseNumber(const string &value,
             const string &type); // Constructor with parameters

  // Changes the type of the number to newType and performs the conversion
  bool convertTo(const string &newType);

  // Accessor methods
  string getNum() const {
    return type + value;
  } // Combines type and value for display
  int getValue() const {
    return stoi(value);
  } // Converts value to integer (if possible)
  string getType() const { return type; } // Returns the type of the number
  void setValue(const string &newValue) {
    value = newValue;
  } // Sets a new value

  // These are operator overloads, this makes it possible to do something like
  // BaseNumber1 + BaseNumber2. Thses are used in the arith function in main.
  inline BaseNumber operator+(const BaseNumber &other) const {
    int resultValue = stoi(this->value) + stoi(other.value);
    BaseNumber num(to_string(resultValue), "0d");
    if (num.type != type) {
      num.convertTo(type);
    }
    return num;
  }

  inline BaseNumber operator-(const BaseNumber &other) const {
    int resultValue = stoi(this->value) - stoi(other.value);
    BaseNumber num(to_string(resultValue), "0d");

    if (num.type != type) {
      num.convertTo(type);
    }
    return num;
  }
};

#endif // MODELPROGRAM_BASENUMBER_H
