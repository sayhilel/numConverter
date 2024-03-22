#pragma once
#ifndef FUNCTS
#define FUNCTS
#include "BaseNumber.h"
#include <string>

using namespace std;

class BaseCalc
{
private:
    BaseNumber *num1;
    BaseNumber *num2;

  string orgType;

    BaseNumber *result;

public:
  // constructors and destructor
  BaseCalc(BaseNumber *, BaseNumber *);
  ~BaseCalc();

  // getters and setters
  string getNum1();
  string getNum2();
  string getResult();

  void setNum1(BaseNumber);
  void setNum2(BaseNumber);

  // arith functions
  void addNum();
  void subNum();
};

#endif
