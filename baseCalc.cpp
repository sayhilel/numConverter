#include "baseCalc.h"
#include "numConverter.h"
#include <string>
using std::string;

BaseCalc::BaseCalc(numConverter *num1, numConverter *num2) {

  orgType = num1->getType();

  if (num1->getType() != "0d") {
    num1->convertManual("0d");
  }

  if (num2->getType() != "0d") {
    num2->convertManual("0d");
  }

  this->num1 = num1;
  this->num2 = num2;
  result = new numConverter("0", "0d");
}

BaseCalc::~BaseCalc() {
  delete num1;
  delete num2;
  delete result;
}

string BaseCalc::getNum1() { return num1->getNum(); }

string BaseCalc::getNum2() { return num2->getNum(); }

string BaseCalc::getResult() { return result->getNum(); };

void BaseCalc::setNum1(numConverter num) {
  orgType = num.getNum().substr(0, 3);
  *(this->num1) = num;
}

void BaseCalc::setNum2(numConverter num) {
  num.convertManual("0d");
  *(this->num2) = num;
}

void BaseCalc::addNum() {
  if (result->getType() != "0d") {
    result->convertManual("0d");
  }

  int n1 = num1->getValue();
  int n2 = num2->getValue();
  int r = n1 + n2;
  result->setNum(to_string(r));
  if (result->getType() != orgType) {
    result->convertManual(orgType);
  }
}

void BaseCalc::subNum() {
  if (result->getType() != "0d") {
    result->convertManual("0d");
  }
  int n1 = num1->getValue();
  int n2 = num2->getValue();
  int r = n1 - n2;
  result->setNum(to_string(r));
  if (result->getType() != orgType) {
    result->convertManual(orgType);
  }
}
