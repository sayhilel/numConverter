#include "baseCalc.h"
#include <iostream>
#include <map>
#include <string>
using std::string;

std::string toLower(const std::string &str);
bool nextCommand(std::string &command, std::string &subCommand,
                 size_t *position);
void seperator();
void iprintMenu();
void greeter();
void printMenu();
string dec2Bin(int dec);
int bin2Dec(string bin);
string hex2Bin(string hex);
string bin2Hex(string bin, int bits);

inline int BOX_WIDTH = 80;
inline std::string BORDER_LINE(BOX_WIDTH, '-');

inline std::string toLower(const std::string &str) {
  std::string result;
  for (char c : str) {
    result += std::tolower(c);
  }
  return result;
}

inline bool nextCommand(std::string &command, std::string &subCommand,
                        size_t *position) {

  std::cin >> command;

  command = toLower(command); // BREAK-ME

  if ((command == "init") || (command == "save") || (command == "stop") ||
      (command == "help"))
    return true;

  if (command == "convert") {
    if (std::cin >> subCommand) {

      subCommand = toLower(subCommand);

      if ((subCommand == "d2b") || (subCommand == "b2h") ||
          (subCommand == "d2h") || (subCommand == "h2b") ||
          (subCommand == "b2d") || (subCommand == "h2d")) {
        return true;
      }
    }
  }

  if (command == "print") {
    if (std::cin >> *position) {
      return true;
    }
  }

  return false;
}

inline void seperator() {
  std::cout << "\033[32m" << '+' << BORDER_LINE << '+' << "\033[0m"
            << std::endl;
}

inline void iprintMenu() {

  seperator();
  std::cout << "Init: Reads the numbers from ifile and stores them in a vector."
            << std::endl;
  std::cout << "Convert : Converts the array" << std::endl;
  std::cout << "    D2B: Converts decimal to binary." << std::endl;
  std::cout << "    B2H: Converts binary to hex." << std::endl;
  std::cout << "    D2H: Converts decimal to hex (built using D2B & B2H)."
            << std::endl;
  std::cout << "    H2B: Converts hex to binary." << std::endl;
  std::cout << "    B2D: Converts binary to decimal." << std::endl;
  std::cout << "    H2D: Converts hex to decimal." << std::endl;
  std::cout << "Save: Saves the array to ofile." << std::endl;
  std::cout << "Print : If no index is provided, it prints the whole array."
            << std::endl;
  seperator();
}
inline void greeter() {

  seperator();
  std::cout << "Welcome, I am C++ program designed for this workshop"
            << std::endl;
  std::cout << "Unfortunately there are some issues in my codebase. Can you "
               "spot and fix them?"
            << std::endl;
  std::cout << "Type \"Help\" to see usage instructions" << std::endl;
  seperator();
}

inline void printMenu() {

  seperator();
  std::cout << "Menu:" << std::endl;
  std::cout << "0. Exit" << std::endl;
  std::cout << "1. Convert to binary" << std::endl;
  std::cout << "2. Convert to hex" << std::endl;
  seperator();
}

inline std::string extractType(std::string *input) {

  // <BREAK-ME>
  std::string type = "0d";

  if (input->size() >= 2 && (*input)[0] == '0') {
    if ((*input)[1] == 'x' || (*input)[1] == 'X') {
      type = "0x";
      *input = input->substr(2);
    } else if ((*input)[1] == 'b' || (*input)[1] == 'B') {
      type = "0b";
      *input = input->substr(2);
    }
  }
  return type;
}

// HEX TO BINARY MAP

inline std::map<char, string> hexToBin = {
    {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
    {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
    {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
    {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}};

inline string hex2Bin(string number) {
  // string where to store binary result
  string binResult = "";

  // loop through hex num and convert to binary
  for (int i = 0; i < number.length(); i++) {
    binResult += hexToBin[number[i]];
  }

  // set up new BinNum object here
  return binResult;
}

inline string bin2Hex(string bin, int bits) {
  // string where to store hex result
  string hexResult = "";
  // check to see if string is % 4, pad accordingly
  if (bits % 4 == 0) {
    string pad = "";
    int size = bits;
    while (size % 4 != 0) {
      pad += "0";
    }
    bin = pad + bin;
  }

  // start from end of string and go to start counting by 4 each time
  int j = bits - 1;
  for (int i = bits - 5; i >= 0; i -= 4) {
    // add each char from map to resultString
    for (auto entry : hexToBin) {
      if (entry.second == bin.substr(i, j)) {
        hexResult = entry.first + hexResult;
        break; // Exit from the loop.
      }
    }
  }

  return hexResult;
}

inline int bin2Dec(string bin) {}

inline string dec2Bin(int dec) {}
