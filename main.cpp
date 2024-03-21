#include "baseCalc.h"
#include "numConverter.h"
#include "util.hpp"
#include <iostream>
#include <ostream>
#include <string>
using std::cin, std::cout, std::cerr, std::endl, std::string;

numConverter *getInput() {
  string inVal;
  cin >> inVal;

  // parse input and store into numConverter object
  string type;
  string value;
  type = extractType(&inVal);
  value = inVal.substr(2, inVal.length());
  return new numConverter(value, type);
}

void arithFunct(numConverter *num1) {
  cout << "Enter a number: " << endl;
  numConverter *num2 = getInput();
  BaseCalc temp(num1, num2);

  int select;
  cout << "Would you like to add or subtract the numbers" << endl;
  cout << "[0] add" << endl;
  cout << "[1] sub" << endl;
  cin >> select;

  if (select == 0) {
    temp.addNum();
  } else if (select == 1) {
    temp.subNum();
  } else {
    cout << "Incorrect input" << endl;
    return;
  }

  cout << temp.getResult() << endl;
}

int main(int argc, char *argv[]) {

  // Variables used
  string command;
  string subCommand;
  size_t position;

  int input;
  double value;

  // Check usage
  if (argc < 4) {
    cerr << "Usage: ./program <ifile> <ofile> <mode>" << endl;
    return 1;
  }

  if (!(std::string(argv[3]) == "0" || std::string(argv[3]) == "1")) {
    std::cerr << "Error : Incorrect mode" << std::endl;
    return 1;
  }

  // Default greeter
  greeter();

  // --------- AUTOMATIC MODE -----------
  //  USE ARGV0 ARGV1 to open file iostreams
  if (string(argv[3]) == "0") {
    std::cout << "Type \"Help\" to see usage instructions" << std::endl;

    while (true) {
      if (!nextCommand(command, subCommand, &position)) {
        cerr << "ERROR: Invalid input" << endl;
        cerr << "Enter \"HELP\" to print out valid commands" << endl;
        continue;
      }

      if (command == "hex") {
        // this should convert all numbers in ifile to hex regardless of
        // starting base
      }

      if (command == "binary") {
        // convert all numbers in ifile to binary regardless of starting base
      }

      if (command == "decimal") {
        // convert all numbers in ifile to decimal regardless of starting base
      }

      if (command == "sum") {
        // sum up all numbers in ifile using the basecalc
        // this will take the base of the first number in ifile
        // setting num2 in baseCalc, effectively summing all numbers to result
      }

      if (command == "help") {
        iprintMenu();
      }

      if (command == "stop") {
        cout << "Exiting...." << endl;
        return 0;
      }
    }
  }

  // Merged modelProgram.cpp
  // --------- MANUAL MODE -----------

  if (string(argv[3]) == "1") {
    // value to have operations performed on
    cout << "Manual mode selected, enter a value:" << endl;
    numConverter *currentNum = getInput();

    // BREAK - ME

    printMenu();

    if (!(cin >> input)) {
      cerr << "ERROR: Inavlid Value" << endl;
      return 1;
    }

    while (input != 0) {
      switch (input) {
      case 1:
        // convert to binary
        currentNum->convert("0b");
        cout << currentNum->getNum() << endl;
        break;
      case 2:
        // convert to hex
        currentNum->convert("0x");
        cout << currentNum->getNum() << endl;
        break;
      case 3:
        // convert to decimal
        currentNum->convert("0d");
        cout << currentNum->getNum() << endl;
        break;
      case 4:
        arithFunct(currentNum);
        break;
      default:
        cout << "Invalid input" << endl;
        break;
      }
      if (input != 0) {
        printMenu();
        cin >> input;
      }
    }
  }
  return 0;
}
