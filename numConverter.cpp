#include "numConverter.h"

numCoverter::numCoverter(string num, string type) {
  this->num = num;
  this->type = type;
}

string numCoverter::convertB2D(string num) {

  int result = 0;

  for (size_t i = 0; i < num.length(); i++) {
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

string numCoverter::convertH2B(string num) {
  string result = "";

  for (size_t i = 0; i < num.length(); i++) {
    if (hexToBin.find(num[i]) == hexToBin.end()) {
      return "ERROR: Invalid binary";
    }
    result += hexToBin[num[i]];
  }
  return result;
}

string numCoverter::convertB2H(string num) {
  string result = "";

  while (num.length() % 4 != 0) {
    num = "0" + num;
  }

  for (size_t i = 0; i < num.length(); i += 4) {
    string temp = num.substr(i, 4);
    for (const auto &pair : hexToBin) {
      if (pair.second == temp) {
        result += pair.first;
      }
    }
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
    } else if (numCoverter::type == "0x") {
      numCoverter::type = newType;
      numCoverter::num = convertH2B(num);
      return true;
    }
  }

  if (newType == "0d") {
    if (numCoverter::type == "0b") {
      numCoverter::type = newType;
      numCoverter::num = convertB2D(num);
      return true;
    } else if (numCoverter::type == "0x") {
      numCoverter::type = newType;
      numCoverter::num = convertB2D(convertH2B(num));
      return true;
    }
  }

  if (newType == "0x") {
    if (numCoverter::type == "0b") {
      numCoverter::type = newType;
      numCoverter::num = convertB2H(num);
      return true;
    } else if (numCoverter::type == "0d") {
      numCoverter::type = newType;
      numCoverter::num = convertB2H(convertD2B(num));
      return true;
    }
  }

  return false;
}
