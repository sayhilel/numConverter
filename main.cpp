#include <iostream>
#include <string>
#include "util.h"

using std::cin, std::cout, std::cerr, std::endl, std::string;


int main(int argc, char* argv[])
{

	string command;
	string subCommand;
	size_t position;
	
	int input;
	double value;

	if(argc < 4){
		cerr << "Usage: ./program <ifile> <ofile> <mode>" << endl;
		return 1;
	}
	
	greeter();
	
	while (true && (string(argv[3]) == "0"))
	{
		if(!nextCommand(command, subCommand, &position)){
			cerr << "ERROR: Invalid input" << endl;
			cerr << "Enter \"HELP\" to print out valid commands" << endl;
			continue;
		}

		if(command == "help"){
			iprintMenu();
		}

		if(command == "stop"){
			cout << "Exiting...." << endl;
			return 0;
		}

		
	}	

	// Merged modelProgram.c
	if(string(argv[3]) == "1"){
	cout << "Manual mode selected, enter a value:" << endl;
	}
	else{
		cerr << "ERROR: Mode must be either 0 or 1" << endl;
		return 1;
	}
	
	if (!(cin >> value)){
		cerr << "ERROR: Inavlid Value" << endl;
		return 1;
	}

	printMenu();
	
	if (!(cin >> input)){
		cerr << "ERROR: Inavlid Value" << endl;
		return 1;
	}
		
	while (input != 0)
	{
		switch (input)
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

	return 0;
}
