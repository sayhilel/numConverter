#pragma once
#ifndef MODELPROGRAM_BASENUMBER_H
#define MODELPROGRAM_BASENUMBER_H

#include <string>
#include <cmath>
#include <map>
#include "util.hpp"

using namespace std;

class BaseNumber
{
private:
    string value; // The numeric value in string representation
    string type;  // The base type ("0b", "0d", "0x")

    // Conversion methods
    void toDecimal();

    void toBinary();

    void toHex();

    inline int toInt()
    {
        int result = 0;
        if (type == "0d")
        {
            result = std::stoi(value);
        }
        else if (type == "0b")
        {
        }
        else if (type == "0x")
        {
        }
        return result;
    };

public:
    // Constructors
    BaseNumber();                                        // Default constructor if needed
    BaseNumber(const string &value, const string &type); // Constructor with parameters

    // Changes the type of the number to newType and performs the conversion
    bool convertTo(const string &newType);

    // Accessor methods
    string getNum() const { return type + value; }              // Combines type and value for display
    int getValue() const { return std::stoi(value); }           // Converts value to integer (if possible)
    string getType() const { return type; }                     // Returns the type of the number
    void setValue(const string &newValue) { value = newValue; } // Sets a new value

    // Overloading + operator
    inline BaseNumber *operator+(const BaseNumber &other) const
    {
        int resultValue = std::stoi(this->value) + std::stoi(other.value);
        BaseNumber *num = new BaseNumber(std::to_string(resultValue), "0d");
        num->convertTo(type);
        return num;
    }

    inline BaseNumber *operator-(const BaseNumber &other) const
    {
        int resultValue = std::stoi(this->value) - std::stoi(other.value);
        BaseNumber *num = new BaseNumber(std::to_string(resultValue), "0d");
        num->convertTo(type);
        return num;
    }
};

#endif // MODELPROGRAM_BASENUMBER_H
