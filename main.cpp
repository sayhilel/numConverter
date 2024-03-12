#include <iostream>
#include <string>
#include "util.h"

using std::cout, std::cerr, std::endl, std::string;

int main(int argc, char* argv[])
{

	string command;
	string subCommand;
	size_t position;
	

	if(argc < 3){
		cerr << "Usage: ./program <ifile> <ofile> " << endl;
		return 1;
	}

	while (true)
	{
		if(!nextCommand(command, subCommand, &position)){
			cout << "Invalid input" << endl;
			cout << "Enter \"HELP\" to print out valid commands" << endl;
			continue;
		}

		if(command == "help"){
			printMenu();
		}

		
	}

	return 0;
}
