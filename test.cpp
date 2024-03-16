#include "numConverter.h"
#include "util.hpp"
#include <iostream>
#include <string>

int main() {
  std::string input;
  std::string type;

  std::cin >> input;
  type = extractType(&input);

  numCoverter *activeNum = new numCoverter(input, type);
  std::cout << activeNum->getNum() << std::endl;

  activeNum->convert("0b");
  std::cout << activeNum->getNum() << std::endl;
  return 0;
}
