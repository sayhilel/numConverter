#ifndef MODELPROGRAM_BASENUMBER_H
#define MODELPROGRAM_BASENUMBER_H

#pragma once
#include <string>
#include <cmath>
#include <map>
#include "util.hpp"

using namespace std;

class BaseNumber {
private:
    string value; // The numeric value in string representation
    string type;  // The base type ("binary", "decimal", "hex")

    // Conversion methods
    void toDecimal();
    void toBinary();
    void toHex();

public:
    // Constructors
    BaseNumber(); // Default constructor if needed
    BaseNumber(const string& value, const string& type); // Constructor with parameters

    // Changes the type of the number to newType and performs the conversion
    bool convertTo(const string& newType);

    // Accessor methods
    string getNum() const { return type + value; } // Combines type and value for display
    int getValue() const { return std::stoi(value); } // Converts value to integer (if possible)
    string getType() const { return type; } // Returns the type of the number
    void setValue(const string& newValue) { value = newValue; } // Sets a new value
};


#endif //MODELPROGRAM_BASENUMBER_H
