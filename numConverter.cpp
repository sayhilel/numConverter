#include "numConverter.h"
#include <cmath>
#include <iostream>
#include <string>

using std::string;

numCoverter::numCoverter(string num, string type) {
  this->num = num;
  this->type = type;
}

string numCoverter::convertB2D(string num) {

  int result = 0;

  for (int i = 0; i < num.length(); i++) {
    if (num[i] != '0' && num[i] != '1') {
      return "ERROR: Invalid binary"; // <BREAK-ME>
    }

    if (num[i] == '1') {
      result += pow(2, (num.length() - i - 1));
    }
  }

  return std::to_string(result);
}

string numCoverter::convertD2B(string num) {
  int n = std::stoi(num);
  string result = "";
  while (n > 0) {
    result = std::to_string(n % 2) + result;
    n /= 2;
  }
  return result;
}

bool numCoverter::convert(string newType) {

  if (newType == numCoverter::type) {
    std::cerr << "ERROR: Number is already of type " << newType << std::endl;
    return false;
  }

  if (newType == "0b") {
    if (numCoverter::type == "0d") {
      numCoverter::type = newType;
      numCoverter::num = convertD2B(num);
      return true;
    }
  }

  if (newType == "0d") {
    if (numCoverter::type == "0b") {
      numCoverter::type = newType;
      numCoverter::num = convertB2D(num);
      return true;
    }
  }
  return false;
}
