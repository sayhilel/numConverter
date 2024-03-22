#include "baseCalc.h"
#include "numConverter.h"
#include "util.hpp"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using std::cin, std::cout, std::cerr, std::endl, std::string, std::vector,
    std::ifstream;

numConverter *getInput() {
  string inVal;
  cin >> inVal;

  if (inVal.size() < 3) {
    cerr << "ERROR: Invalid input" << endl;
    exit(1);
  }
  // parse input and store into numConverter object
  string type;
  string value;
  type = extractType(inVal);
  value = extractValue(inVal);
  return new numConverter(value, type);
}

void arithFunct(numConverter *num1) {
  cout << "Enter a number: " << endl;
  numConverter *num2 = getInput();
  BaseCalc temp(num1, num2);

  int select;
  cout << "Choose a function to perform:" << endl;
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

int main(int argc, char **argv) {

  // Variables used
  string command;
  string subCommand;
  size_t position;

  vector<string> numArray;
  string type;
  string value;
  int input;
  // double value;

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

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        continue;
      }

      if (command == "stop") {
        cout << "Exiting program" << endl;
        break;
      }

      if (command == "init") {
        ifstream file((argv[1]));
        if (!file) {
          cerr << "ERROR: File not found" << endl;
          exit(1);
        }

        string readNum;
        while (file >> readNum) {
          numArray.push_back(readNum);
        }

        cout << "Read " << numArray.size() << " number(s)" << endl;
        file.close();
        continue;
      }

      if (command == "convert") {
        for (size_t i = 0; i < numArray.size(); i++) {
          type = extractType(numArray[i]);
          value = extractValue(numArray[i]);
          numConverter currentNum = numConverter(value, type);
          currentNum.convert(subCommand);
          numArray[i] = currentNum.getNum();
        }
      }

      if (command == "print") {
        for (size_t i = 0; i < numArray.size(); i++) {
          cout << "printing: " << numArray[i] << endl;
        }
        continue;
      }

      if (command == "save") {
        ofstream file((argv[2]));
        if (!file) {
          cerr << "ERROR: File not found" << endl;
          exit(1);
        }
        for (size_t i = 0; i < numArray.size(); i++) {
          file << numArray[i] << endl;
        }
        cout << "File saved" << endl;
        file.close();
      }

      if (command == "total") {
        double total = 0;
        for (size_t i = 0; i < numArray.size(); i++) {
          type = extractType(numArray[i]);
          value = extractValue(numArray[i]);
          numConverter currentNum = numConverter(value, type);
          if (type == "0b") {
            currentNum.convert("b2d");
          }
          if (type == "0x") {
            currentNum.convert("h2d");
          }
          total += currentNum.getValue();
        }
        type = extractType(numArray[0]);

        numConverter totalNum = numConverter(to_string(total), "0d");
        if (type != "0d") {
          totalNum.convertManual(type);
        }

        cout << "Total: " << totalNum.getNum() << endl;
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
        currentNum->convertManual("0b");
        cout << currentNum->getNum() << endl;
        break;
      case 2:
        // convert to hex
        currentNum->convertManual("0x");
        cout << currentNum->getNum() << endl;
        break;
      case 3:
        // convert to decimal
        currentNum->convertManual("0d");
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
