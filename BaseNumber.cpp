#include "BaseNumber.h"

BaseNumber::BaseNumber() {

}

BaseNumber::BaseNumber(const string& value, const string& type) : value(value), type(type) {
}

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
            decimalResult += (value[i] - '0') * static_cast<int>(pow(2, value.length() - i - 1));
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
                decimalResult += static_cast<int>(pow(2, binaryString.length() - i - 1));
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




bool BaseNumber::convertTo(const string& newType) {
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

