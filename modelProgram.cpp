#include <iostream>

#include "modelProgram.hpp"
using std::cin, std::cout, std::endl;

int main()
{

	// just an idea but we could have them load a file using the command line arguments
	cout << "I work properly" << std::endl;

	// Create Menu for user interaction
	int input;
	cin >> input;

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
			// printMenu
			cin >> input;
		}
	}

	return 0;
}
