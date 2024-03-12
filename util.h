#pragma once
#include <string>

const int BOX_WIDTH = 120;
const std::string BORDER_LINE(BOX_WIDTH, '-');

std::string toLower(const std::string& str);
bool nextCommand(std::string& command, std::string& subCommand, size_t* position);
void seperator();
void printMenu();
void greeter();
