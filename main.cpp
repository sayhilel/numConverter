#include <iostream>
#include <ostream>
#include <string>
#include "util.hpp"
using std::cin, std::cout, std::cerr, std::endl, std::string;

int main(int argc, char *argv[])
{

  // Variables used
  string command;
  string subCommand;
  size_t position;

  int input;
  double value;

  // Check usage
  if (argc < 4)
  {
    cerr << "Usage: ./program <ifile> <ofile> <mode>" << endl;
    return 1;
  }

  if (!(std::string(argv[3]) == "0" || std::string(argv[3]) == "1"))
  {
    std::cerr << "Error : Incorrect mode" << std::endl;
    return 1;
  }

  // Default greeter
  greeter();

  // --------- AUTOMATIC MODE -----------
  //  USE ARGV0 ARGV1 to open file iostreams
  if (string(argv[3]) == "0")
  {
    std::cout << "Type \"Help\" to see usage instructions" << std::endl;

    while (true)
    {
      if (!nextCommand(command, subCommand, &position))
      {
        cerr << "ERROR: Invalid input" << endl;
        cerr << "Enter \"HELP\" to print out valid commands" << endl;
        continue;
      }

      if (command == "hex")
      {
        // this should convert all numbers in ifile to hex regardless of starting base
      }

      if (command == "binary")
      {
        // convert all numbers in ifile to binary regardless of starting base
      }

      if (command == "decimal")
      {
        // convert all numbers in ifile to decimal regardless of starting base
      }

      if (command == "sum")
      {
        // sum up all numbers in ifile using the basecalc
        // this will take the base of the first number in ifile
        // setting num2 in baseCalc, effectively summing all numbers to result
      }

      if (command == "help")
      {
        iprintMenu();
      }

      if (command == "stop")
      {
        cout << "Exiting...." << endl;
        return 0;
      }
    }
  }

  // Merged modelProgram.cpp
  // --------- MANUAL MODE -----------

  if (string(argv[3]) == "1")
  {
    cout << "Manual mode selected, enter a value:" << endl;
    // INIT NUMBER CLASS

    // BREAK - ME

    printMenu();

    if (!(cin >> input))
    {
      cerr << "ERROR: Inavlid Value" << endl;
      return 1;
    }

    while (input != 0)
    {
      switch (input)
      {
      case 1:
        // convert to binary
      case 2:
        // convert to hex
      case 3:
        // add numbers together
        // prompt for second value
        // create binCalc
        // perform subtraction
        // print result
      case 4:
        // substract numbers
        // prompt for second value
        // create binCalc
        // perform subtraction
        // print result
      default:
        cout << "Invalid input" << endl;
        break;
      }
      if (input != 0)
      {
        printMenu();
        cin >> input;
      }
    }
  }
  return 0;
}
