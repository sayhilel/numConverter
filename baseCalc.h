#pragma once
#ifndef FUNCTS
#define FUNCTS
#include "numConverter.h"
#include <string>
using std::string;

class BaseCalc
{
private:
  numConverter *num1;
  numConverter *num2;

  string orgType;

  numConverter *result;

public:
  // constructors and destructor
  BaseCalc(numConverter *, numConverter *);
  ~BaseCalc();

  // getters and setters
  string getNum1();
  string getNum2();
  string getResult();

  void setNum1(numConverter);
  void setNum2(numConverter);

  // arith functions
  void addNum();
  void subNum();
};

#endif
