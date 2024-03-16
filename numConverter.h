#pragma once
#include "numConverter.h"
#include <iostream>
#include <string>
using std::string;

class numCoverter {
private:
  string num;
  string type;

  string convertB2D(string num);
  string convertD2B(string num);

public:
  // Constructor
  numCoverter(string num, string type);
  // Changes the type of the number to newType
  bool convert(string newType);
  // Concatenates the number and its type and returns
  inline string getNum() { return type + num; }
};
