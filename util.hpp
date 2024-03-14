#include <iostream>
#include <string>

std::string toLower(const std::string &str);
bool nextCommand(std::string &command, std::string &subCommand, size_t *position);
void seperator();
void iprintMenu();
void greeter();
void printMenu();
std::string toBinary(int dec);

int BOX_WIDTH = 80;
std::string BORDER_LINE(BOX_WIDTH, '-');

std::string toLower(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += std::tolower(c);
    }
    return result;
}

bool nextCommand(std::string &command, std::string &subCommand, size_t *position)
{

    std::cin >> command;

    command = toLower(command); // BREAK-ME

    if ((command == "init") || (command == "save") || (command == "stop") || (command == "help"))
        return true;

    if (command == "convert")
    {
        if (std::cin >> subCommand)
        {

            subCommand = toLower(subCommand);

            if ((subCommand == "d2b") || (subCommand == "b2h") || (subCommand == "d2h") || (subCommand == "h2b") || (subCommand == "b2d") || (subCommand == "h2d"))
            {
                return true;
            }
        }
    }

    if (command == "print")
    {
        if (std::cin >> *position)
        {
            return true;
        }
    }

    return false;
}

void seperator()
{
    std::cout << "\033[32m" << '+' << BORDER_LINE << '+' << "\033[0m" << std::endl;
}

void iprintMenu()
{

    seperator();
    std::cout << "Init: Reads the numbers from ifile and stores them in a vector." << std::endl;
    std::cout << "Convert : Converts the array" << std::endl;
    std::cout << "    D2B: Converts decimal to binary." << std::endl;
    std::cout << "    B2H: Converts binary to hex." << std::endl;
    std::cout << "    D2H: Converts decimal to hex (built using D2B & B2H)." << std::endl;
    std::cout << "    H2B: Converts hex to binary." << std::endl;
    std::cout << "    B2D: Converts binary to decimal." << std::endl;
    std::cout << "    H2D: Converts hex to decimal." << std::endl;
    std::cout << "Save: Saves the array to ofile." << std::endl;
    std::cout << "Print : If no index is provided, it prints the whole array." << std::endl;
    seperator();
}
void greeter()
{

    seperator();
    std::cout << "Welcome, I am C++ program designed for this workshop" << std::endl;
    std::cout << "Unfortunately there are some issues in my codebase. Can you spot and fix them?" << std::endl;
    std::cout << "Type \"Help\" to see usage instructions" << std::endl;
    seperator();
}

void printMenu()
{

    seperator();
    std::cout << "Menu:" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Convert to binary" << std::endl;
    std::cout << "2. Convert to hex" << std::endl;
    seperator();
}

std::string toBinary(int dec)
{
    // add logic here if u have it
    return "";
}