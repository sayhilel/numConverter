#pragma once
#ifndef NUMCONVERT
#define NUMCONVERT
#include <string>
#include <cmath>
#include <map>

#include "util.hpp"

using namespace std;

class numConverter
{
private:
  string num;
  string type;

  string convertB2D(string num);
  string convertD2B(string num);
  string convertH2B(string num);
  string convertB2H(string num);

public:
  // Constructor
  numConverter();
  numConverter(string num, string type);
  // Changes the type of the number to newType
  bool convert(string newType);
  // Concatenates the number and its type and returns
  inline string getNum() { return type + num; }

  // operator overloads for arith
  numConverter *operator+(const numConverter &);
  numConverter *operator-(const numConverter &);
};
#endif // !NUMCONVERT
