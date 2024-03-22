#include "baseCalc.h"

BaseCalc::BaseCalc(BaseNumber *num1, BaseNumber *num2) {

    orgType = num1->getType();

    if (num1->getType() != "0d") {
        num1->convertTo("0d");
    }

    if (num2->getType() != "0d") {
        num2->convertTo("0d");
    }

    this->num1 = num1;
    this->num2 = num2;
    result = new BaseNumber("0", "0d");
}

BaseCalc::~BaseCalc() {
    delete num1;
    delete num2;
    delete result;
}

string BaseCalc::getNum1() { return num1->getNum(); }

string BaseCalc::getNum2() { return num2->getNum(); }

string BaseCalc::getResult() {
    return result->getNum();
};

void BaseCalc::setNum1(BaseNumber num) {
    orgType = num.getNum().substr(0, 3);
    *(this->num1) = num;
}

void BaseCalc::setNum2(BaseNumber num) {
    num.convertTo("0d");
    *(this->num2) = num;
}

void BaseCalc::addNum() {
    if (result->getType() != "0d") {
        result->convertTo("0d");
    }

    int n1 = num1->getValue();
    int n2 = num2->getValue();
    int r = n1 + n2;
    result->setValue(to_string(r));
    if (result->getType() != orgType) {
        result->convertTo(orgType);
    }
}

void BaseCalc::subNum() {
    if (result->getType() != "0d") {
        result->convertTo("0d");
    }
    int n1 = num1->getValue();
    int n2 = num2->getValue();
    int r = n1 - n2;
    result->setValue(to_string(r));
    if (result->getType() != orgType) {
        result->convertTo(orgType);
    }
}
