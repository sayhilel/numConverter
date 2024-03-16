#include "util.hpp"
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
		if (!(cin >> value))
		{
			cerr << "ERROR: Inavlid Value" << endl;
			return 1;
		}

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

			default:
				cout << "Invalid input" << endl;
				break;

				if (input != 0)
				{
					printMenu();
					cin >> input;
				}
			}
		}
	}

	return 0;
}
