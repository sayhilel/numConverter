#include "baseCalc.h"
#include "BaseNumber.h"
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

BaseNumber* getInput() {
    string inVal;

    // Loop until valid input is received
    while (true) {
        cout << "Enter value and type (Prefix with 0x for hex, 0b for binary, or 0d for decimal)\n> ";
        cin >> inVal;

        if (inVal.length() > 2 && (inVal.substr(0, 2) == "0x" || inVal.substr(0, 2) == "0b" || inVal.substr(0, 2) == "0d")) {
            string type = inVal.substr(0, 2); // Extract the type based on the prefix
            string value = inVal.substr(2); // Extract the value after the prefix

            return new BaseNumber(value, type);
        } else {
            cout << "Invalid input. Try again." << endl;
        }
    }
}




//void arithFunct(BaseNumber *num1) {
//    cout << "Enter a number: " << endl;
//    BaseNumber *num2 = getInput();
//    BaseCalc temp(num1, num2);
//
//    int select;
//    cout << "Choose a function to perform:" << endl;
//    cout << "[0] add" << endl;
//    cout << "[1] sub" << endl;
//    cin >> select;
//
//    if (select == 0) {
//        temp.addNum();
//    } else if (select == 1) {
//        temp.subNum();
//    } else {
//        cout << "Incorrect input" << endl;
//        return;
//    }
//
//    cout << temp.getResult() << endl;
//}

int getMenuChoice() {
    int choice;
    cout << "Enter your choice: ";
    while (!(cin >> choice)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input
        cout << "Invalid input. Please enter a number: ";
    }
    return choice;
}

void handleMenuChoice(int choice, BaseNumber* currentNum) {
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
            // Arithmetic operations logic here
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }
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

    greeter(); // Assume greeter() is defined elsewhere to print a greeting or instructions

    if (mode == "1") {
        cout << "Manual mode selected!" << endl;
        BaseNumber* currentNum = getInput();

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
        delete currentNum; // Clean up dynamically allocated memory
    } else if (mode == "0") {
        cout << "Automatic mode selected. Type \"Help\" to see usage instructions." << endl;

        string command, subCommand;
        size_t position;
        while (true) {
            if (!nextCommand(command, subCommand, &position)) {
                cerr << "ERROR: Invalid input. Enter \"HELP\" to print out valid commands." << endl;
                continue;
            }

            if (command == "hex") {
                // this should convert all numbers in ifile to hex regardless of
                // starting base
            }
            //TODO:....rest
            if (command == "stop") {
                cout << "Exiting..." << endl;
                break;
            }
        }
    }

    return 0;
}
