#include "util.h"
#include <iostream>

std::string toLower(const std::string& str) {
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

bool nextCommand(std::string& command, std::string& subCommand, size_t* position){
	
	std::cin >> command;
		
	command = toLower(command); //BREAK-ME

	if ((command == "init") || (command == "save"))
		return true;


	if (command == "convert"){
		if(std::cin >> subCommand){
			
			subCommand = toLower(subCommand);		

			if((subCommand == "d2b")||(subCommand == "b2h")||(subCommand == "d2h")||(subCommand == "h2b")||(subCommand == "b2d")||(subCommand == "h2d")){
				return true;
			}
		}
	}

	if (command == "print"){
		if(std::cin >> *position){
			return true;
		}
	}

	return false;
}
