#pragma once
#include <string>

std::string toLower(const std::string& str);
bool nextCommand(std::string& command, std::string& subCommand, size_t* position);
void seperator();
void printMenu();
void greeter();
