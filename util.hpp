#pragma once
#include <iostream>
#include <map>
#include <string>
using std::string, std::cout, std::endl;

std::string toLower(const std::string &str);
bool nextCommand(std::string &command, std::string &subCommand,
                 size_t *position);
void seperator();
void iprintMenu();
void greeter();
void printMenu();

inline int BOX_WIDTH = 80;
inline std::string BORDER_LINE(BOX_WIDTH, '-');

inline std::string toLower(const std::string &str) {
  std::string result;
  for (char c : str) {
    result += std::tolower(c);
  }
  return result;
}

inline bool nextCommand(std::string &command, std::string &subCommand) {

  std::cin >> command;

  command = toLower(command); // BREAK-ME

  if ((command == "init") || (command == "save") || (command == "stop") ||
      (command == "help") || (command == "print") || (command == "total"))
    return true;

  if (command == "convert") {
    if (std::cin >> subCommand) {

      subCommand = toLower(subCommand);

      if ((subCommand == "hex") || (subCommand == "bin") ||
          (subCommand == "dec")) {
        return true;
      }
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
  std::cout << "    HEX: Converts read values to hex." << std::endl;
  std::cout << "    BIN: Converts read values to binary" << std::endl;
  std::cout << "    DEC: Converts read values to decimal" << std::endl;
  std::cout << "Save: Saves the array to ofile." << std::endl;
  std::cout << "Print : Prints the active working array" << std::endl;
  std::cout << "Total : Prints the total of the active working array"
            << std::endl;
  std::cout << "Stop : Exits the program" << std::endl;

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
  cout << "Menu:" << std::endl;
  cout << "0. Exit" << std::endl;
  cout << "1. Convert to binary" << std::endl;
  cout << "2. Convert to hex" << std::endl;
  cout << "3. Convert to decimal" << endl;
  cout << "4. Arithmetic Operations" << endl;
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
