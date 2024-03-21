#include "baseCalc.h"
#include "numConverter.h"
#include <string>
using std::string;

BaseCalc::BaseCalc(numConverter num1, numConverter num2)
{

    orgType = num1.getNum().substr(0, 3);
    num1.convert("0d");
    num2.convert("0d");
    *(this->num1) = num1;
    *(this->num2) = num2;
    result = new numConverter("0", "0d");
}

BaseCalc::~BaseCalc()
{
    delete num1;
    delete num2;
    delete result;
}

string BaseCalc::getNum1() { return num1->getNum(); }

string BaseCalc::getNum2() { return num2->getNum(); }

string BaseCalc::getResult()
{
    return "";
};

void BaseCalc::setNum1(numConverter num)
{
    orgType = num.getNum().substr(0, 3);
    *(this->num1) = num;
}

void BaseCalc::setNum2(numConverter num)
{
    num.convert("0d");
    *(this->num2) = num;
}

void BaseCalc::addNum()
{
    result->convert("0d");
    result = *num1 + *num2;
    result->convert(orgType);
}

void BaseCalc::subNum()
{
    result->convert("0d");
    result = *num1 - *num2;
    result->convert(orgType);
}
