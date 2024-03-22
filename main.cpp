#include "BaseNumber.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// returns true if there's overflow, false if there's not
bool oFChkr(int test) {
  if (test < 0 || test > 268435455) {
    return true;
  } else {
    return false;
  }
}

BaseNumber *getInput() {
  string inVal;

  // Loop until valid input is received
  while (true) {
    cout << "Enter value and type (Prefix with 0x for hex, 0b for binary, or "
            "0d for decimal)\n> ";
    cin >> inVal;

    if (inVal.length() > 2 &&
        (inVal.substr(0, 2) == "0x" || inVal.substr(0, 2) == "0b" ||
         inVal.substr(0, 2) == "0d")) {
      string type = inVal.substr(0, 2);
      string value = inVal.substr(2);

      BaseNumber *newNum = new BaseNumber(value, type);
      if (type != "0d") {
        newNum->convertTo("0d");
      }
      if (!oFChkr(newNum->getValue())) {
        if (newNum->getType() != type) {

          newNum->convertTo(type);
        }
        return newNum;
      }

      delete newNum;
    } else {
      cout << "Invalid input. Try again." << endl;
    }
  }
}

BaseNumber arithFunct(BaseNumber *num1) {
  string typeTo = num1->getType();
  cout << "Enter a number: " << endl;
  BaseNumber *num2 = getInput();
  BaseNumber *result = new BaseNumber("0", "0d");
  // BaseCalc temp(num1, num2);

  if (num1->getType() != "0d") {
    num1->convertTo("0d");
  }

  if (num2->getType() != "0d") {
    num2->convertTo("0d");
  }

  int select;
  cout << "Choose a function to perform:" << endl;
  cout << "[0] add" << endl;
  cout << "[1] sub" << endl;

  while (1) {
    cin >> select;

    if (select == 0) {
      result = *num1 + *num2;
      break;
    } else if (select == 1) {
      result = *num1 - *num2;
      break;

    } else {
      cout << "Incorrect input, try again" << endl;
    }
  }

  if (result->getValue() < 0 || result->getValue() > 268435455) {
    throw std::overflow_error("Overflow, number can't be displayed");
  }

  if (result->getType() != typeTo) {
    result->convertTo(typeTo);
  }
  cout << result->getNum() << endl;
  return *result;
}

int getMenuChoice() {
  int choice;
  cout << "Enter your choice: ";
  while (!(cin >> choice)) {
    cin.clear(); // Clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please enter a number: ";
  }
  return choice;
}

void handleMenuChoice(int choice, BaseNumber *currentNum) {
  // Handle the choice here. For example:
  switch (choice) {
  case 1:
    cout << "Converting to binary..." << endl;
    currentNum->convertTo("0b");
    cout << currentNum->getNum() << endl;
    break;
  case 2:
    cout << "Converting to hex..." << endl;
    currentNum->convertTo("0x");
    cout << currentNum->getNum() << endl;
    break;
  case 3:
    cout << "Converting to decimal..." << endl;
    currentNum->convertTo("0d");
    cout << currentNum->getNum() << endl;
    break;
  case 4:
    cout << "Performing arithmetic operations..." << endl;
    try {
      *currentNum = arithFunct(currentNum);
    } catch (const std::exception &e) {
      std::cerr << e.what() << endl;
    }
    break;
  default:
    cout << "Invalid choice." << endl;
    break;
  }
}
void initializeArray(vector<BaseNumber> &numArray, string ifile) {
  ifstream file(ifile);
  if (!file) {
    cerr << "ERROR: File not found" << endl;
    exit(1);
  }
  string num;
  while (file >> num) {
    if (num.length() < 3) {
      cerr << "ERROR: Invalid input, continuiung" << endl;
      continue;
    }
    BaseNumber currentNum = BaseNumber(num.substr(2), num.substr(0, 2));
    numArray.push_back(currentNum);
  }

  if (numArray.empty()) {
    cerr << "ERROR: No valid numbers found in file" << endl;
    exit(1);
  }

  cout << "Array initialized" << endl;
  file.close();
}

void convertArray(vector<BaseNumber> &numArray, string type) {
  for (size_t i = 0; i < numArray.size(); i++) {
    numArray[i].convertTo(prefixMap[type]);
    cout << "Converted: " << numArray[i].getNum() << endl;
  }
}

void saveArray(vector<BaseNumber> &numArray, string ofile) {
  ofstream file(ofile);
  if (!file) {
    cerr << "ERROR: File not found" << endl;
    exit(1);
  }
  for (size_t i = 0; i < numArray.size(); i++) {
    file << numArray[i].getNum() << endl;
  }

  cout << "Array Saved" << endl;
  file.close();
}

string totalArray(vector<BaseNumber> &numArray) {

  string initalType = numArray[0].getType();
  string currentType;

  int total = 0;
  for (size_t i = 0; i < numArray.size(); i++) {
    currentType = numArray[i].getType();
    numArray[i].convertTo("0d");
    total += numArray[i].getValue();
    numArray[i].convertTo(currentType);
  }

  BaseNumber totalNum = BaseNumber(to_string(total), initalType);
  return totalNum.getNum();
}

int main(int argc, char **argv) {
  if (argc < 4) {
    cerr << "Usage: ./program <ifile> <ofile> <mode>" << endl;
    return 1;
  }

  string mode(argv[3]);
  if (mode != "0" && mode != "1") {
    cerr << "Error: Incorrect mode" << endl;
    return 1;
  }

  greeter();

  if (mode == "1") {
    cout << "Manual mode selected!" << endl;
    BaseNumber *currentNum = getInput();

    int choice = -1;
    while (choice != 0) {
      printMenu();
      choice = getMenuChoice();
      if (choice == 0) {
        cout << "Exiting..." << endl;
        break;
      }
      handleMenuChoice(choice, currentNum);
    }
    delete currentNum;
  } else if (mode == "0") {
    cout << "Automatic mode selected. Type \"Help\" to see usage instructions."
         << endl;
    iprintMenu();
    string command, subCommand;
    size_t position;
    vector<BaseNumber> numArray;
    while (true) {
      if (!nextCommand(command, subCommand, &position)) {
        cerr << "ERROR: Invalid input" << endl;
        cerr << "Enter \"HELP\" to print out valid commands" << endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        continue;
      }

      if (command == "help") {
        iprintMenu();
        continue;
      }

      if (command == "stop") {
        cout << "Exiting..." << endl;
        break;
      }

      if (command == "init") {
        initializeArray(numArray, argv[1]);
        continue;
      }

      if (command == "convert") {
        if (numArray.empty()) {
          cerr << "ERROR: Array is empty" << endl;
          continue;
        }
        convertArray(numArray, subCommand);
        continue;
      }

      if (command == "print") {
        if (numArray.empty()) {
          cerr << "ERROR: Array is empty" << endl;
          continue;
        }
        for (size_t i = 0; i < numArray.size(); i++) {
          cout << i + 1 << ") " << numArray[i].getNum() << endl;
        }
        continue;
      }

      if (command == "save") {
        if (numArray.empty()) {
          cerr << "ERROR: Array is empty" << endl;
          continue;
        }

        saveArray(numArray, argv[2]);
        continue;
      }

      if (command == "total") {
        if (numArray.empty()) {
          cerr << "ERROR: Array is empty" << endl;
          continue;
        }

        cout << "Total:" << totalArray(numArray) << endl;
      }
    }
  }

  return 0;
}
