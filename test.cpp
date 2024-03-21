#include <iostream>
#include <string>
#include "numConverter.h"
#include "baseCalc.h"
using std::string, std::cout, std::endl;

void additionTest()
{
  numConverter *t1 = new numConverter("A", "0x");
  numConverter *t2 = new numConverter("5", "0x");
  BaseCalc *test = new BaseCalc(t1, t2);
  test->addNum();
  cout << test->getResult() << endl;
}

void subtractionTest()
{
  numConverter *t1 = new numConverter("A", "0x");
  numConverter *t2 = new numConverter("5", "0x");
  BaseCalc *test = new BaseCalc(t1, t2);
  test->subNum();
  std::cout << test->getResult() << std::endl;
}

int main(int argc, char **argv)
{
  additionTest();
  subtractionTest();

  cout << "0xNUM for hex\n0bNUM for bin\nNUM for dec\n";
  string input;
  string type;
  string newType;
  cin >> input;
  type = extractType(&input);

  numConverter *activeNum = new numConverter(input, type);
  std::cout << activeNum->getNum() << std::endl;

  std::cout << "enter new type 0x, 0b, 0d " << std::endl;

  std::cin >> newType;

  activeNum->convert(newType);
  std::cout << activeNum->getNum() << std::endl;
  return 0;
}
