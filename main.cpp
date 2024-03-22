// This is a little nitpicky but when importing files convention is to put
// libraries on top and local files at the bottom.
#include "BaseNumber.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>
// This isn't good practice, better to do something like (std::string,
// std::vector ...)
using namespace std;

// returns true if there's overflow, false if there's not
bool oFChkr(int test) {
  if (test < 0 || test > 268435455) {
    return true;
  } else {
    return false;
  }
}

// Handles receiving input for the program, checking the prefix and size of the
// number entered
BaseNumber *getInput() {
  string inVal;

  // Loop until valid input is received
  while (true) {
    cout << "Enter value and type (Prefix with 0x for hex, 0b for binary, or "
            "0d for decimal)\n> ";
    cin >> inVal;

    // prefix check here
    if (inVal.length() > 2 &&
        (inVal.substr(0, 2) == "0x" || inVal.substr(0, 2) == "0b" ||
         inVal.substr(0, 2) == "0d")) {
      string type = inVal.substr(0, 2);
      string value = inVal.substr(2);

      BaseNumber *newNum = new BaseNumber(value, type);
      if (type != "0d") {
        newNum->convertTo("0d");
      }

      // overflow check here
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

// This function handles adding and subtracting baseNumbers
BaseNumber arithFunct(BaseNumber *num1) {
  string typeTo = num1->getType();
  cout << "Enter a number: " << endl;
  BaseNumber *num2 = getInput();
  BaseNumber result("0", "0d");

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

  // checking for overflow here, throwing an overflow exception
  if (result.getValue() < 0 || result.getValue() > 268435455) {
    throw std::overflow_error("Overflow, number can't be displayed");
  }

  if (result.getType() != typeTo) {
    result.convertTo(typeTo);
  }

  cout << result.getNum() << endl;
  delete num2;
  return result;
}

// gets number for menu in manualMode of the program
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

// this handles the choice from the function above calling different functions
// for the various operations that the calculator can perform
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
    // try and catch statement here for exception handling
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

// initializing the array by reading in from the in file and creating a vector
// of BaseNumbers
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

// performs base conversions on array from file
void convertArray(vector<BaseNumber> &numArray, string type) {
  for (size_t i = 0; i < numArray.size(); i++) {
    numArray[i].convertTo(prefixMap[type]);
    cout << "Converted: " << numArray[i].getNum() << endl;
  }
}

// writes the array in its current state to the out file
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

// sums up all the numbers in the array, returns sum as type of the first number
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

  BaseNumber totalNum = BaseNumber(to_string(total), "0d");
  totalNum.convertTo(initalType);
  return totalNum.getNum();
}

int main(int argc, char **argv) {
  // handling incorrect usage
  if (argc < 4) {
    cerr << "Usage: ./program <ifile> <ofile> <mode>" << endl;
    return 1;
  }

  // handling incorrect mode selection
  string mode(argv[3]);
  if (mode != "0" && mode != "1") {
    cerr << "Error: Incorrect mode" << endl;
    return 1;
  }

  // prints out inital instructions explaining concept of program and what not
  greeter();

  // manual Mode (basic num calculator for conversions and adding and subtration
  // of numbers of different bases)
  if (mode == "1") {
    cout << "Manual mode selected!" << endl;
    BaseNumber *currentNum = getInput();

    int choice = -1;

    // Menu loop, can keep entering choices until 0 is entered
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
    // Automatic mode operations done on numbers in ifile
  } else if (mode == "0") {
    cout << "Automatic mode selected. Type \"Help\" to see usage instructions."
         << endl;
    iprintMenu();

    // variables for auto mode
    string command, subCommand;
    size_t position;
    vector<BaseNumber> numArray;

    // Menu loop with different operations available
    while (true) {
      // handles validating inputs
      if (!nextCommand(command, subCommand, &position)) {
        cerr << "ERROR: Invalid input" << endl;
        cerr << "Enter \"HELP\" to print out valid commands" << endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        continue;
      }

      // prints out available commands
      if (command == "help") {
        iprintMenu();
        continue;
      }

      // exits program
      if (command == "stop") {
        cout << "Exiting..." << endl;
        break;
      }

      // initalizes vector from initializeArray function
      if (command == "init") {
        initializeArray(numArray, argv[1]);
        continue;
      }

      // calls convert function
      if (command == "convert") {
        if (numArray.empty()) {
          cerr << "ERROR: Array is empty" << endl;
          continue;
        }
        convertArray(numArray, subCommand);
        continue;
      }

      // prints out array in current state
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

      // writes array to out file (ofile)
      if (command == "save") {
        if (numArray.empty()) {
          cerr << "ERROR: Array is empty" << endl;
          continue;
        }

        saveArray(numArray, argv[2]);
        continue;
      }

      // returns the sum of all the numbers in array
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
