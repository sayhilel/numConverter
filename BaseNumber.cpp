#include "BaseNumber.h"

// Constructors

BaseNumber::BaseNumber() {}

BaseNumber::BaseNumber(const string &value, const string &type)
    : value(value), type(type) {}

// Conversion methods (decimal, binary, hexadecimal)

void BaseNumber::toDecimal() {
  // Initialize result variable
  int decimalResult = 0;

  if (type == "0b") {
    // Binary to Decimal conversion
    for (size_t i = 0; i < value.length(); ++i) {
      if (value[i] != '0' && value[i] != '1') {
        cout << "ERROR: Invalid binary\n";
        return; // Exit on invalid binary input
      }
      // Accumulate binary to decimal conversion result
      decimalResult +=
          (value[i] - '0') * static_cast<int>(pow(2, value.length() - i - 1));
    }
  } else if (type == "0x") {
    // Convert hex to binary
    string binaryString = "";
    for (size_t i = 0; i < value.length(); ++i) {
      if (hexToBin.find(value[i]) == hexToBin.end()) {
        cout << "ERROR: Invalid hex\n";
        return; // Exit on invalid hexadecimal input
      }
      binaryString += hexToBin[value[i]];
    }

    // Convert binary string to decimal
    for (size_t i = 0; i < binaryString.length(); ++i) {
      if (binaryString[i] == '1') {
        decimalResult +=
            static_cast<int>(pow(2, binaryString.length() - i - 1));
      }
    }
  } else {
    cout << "ERROR: Unsupported type for conversion\n";
    return;
  }

  // Update the number's type and value to the converted result
  type = "0d"; // set type to decimal
  value = to_string(decimalResult);
}

void BaseNumber::toBinary() {
  // Initialize result variable
  string binaryString = "";

  if (type == "0d") {
    // Decimal to binary conversion
    int n = stoi(value);
    while (n > 0) {
      binaryString = to_string(n % 2) + binaryString;
      n /= 2;
    }
  } else if (type == "0x") {
    // Convert hex to binary
    for (size_t i = 0; i < value.length(); ++i) {
      if (hexToBin.find(value[i]) == hexToBin.end()) {
        cout << "ERROR: Invalid hex\n";
        return; // Exit on invalid hexadecimal input
      }
      binaryString += hexToBin[value[i]];
    }
  } else {
    cout << "ERROR: Unsupported type for conversion\n";
    return;
  }

  // Update the number's type and value to the converted result
  type = "0b"; // set type to binary
  value = binaryString;
}

void BaseNumber::toHex() {
  // Initialize result variable
  string hexResult = "";

  toBinary();

  while (value.length() % 4 != 0) {
    value = "0" + value;
  }

  for (size_t i = 0; i < value.length(); i += 4) {
    string temp = value.substr(i, 4);
    for (const auto &pair : hexToBin) {
      if (pair.second == temp) {
        hexResult += pair.first;
      }
    }
  }

  // Update the number's type and value to the converted result
  type = "0x"; // set type to hex
  value = hexResult;
}

// this method takes the number type and performs different conversions to get
// it to the desired type

bool BaseNumber::convertTo(const string &newType) {
  if (newType == this->type) {
    cerr << "ERROR: Number is already of type " << newType << endl;
    return false;
  }

  string conversionResult;

  if (newType == "0b") { // Convert to binary
    if (type == "0d" || type == "0x") {
      toBinary();
    }
  } else if (newType == "0d") { // Convert to decimal
    if (type == "0b" || type == "0x") {
      toDecimal();
    }
  } else if (newType == "0x") { // Convert to hexadecimal
    if (type == "0b" || type == "0d") {
      toHex();
    }
  } else {
    cerr << "ERROR: Invalid target type " << newType << endl;
    return false;
  }

  return true;
}
