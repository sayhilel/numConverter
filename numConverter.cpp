#include "numConverter.h"

numConverter::numConverter(string num, string type)
{
  this->num = num;
  this->type = type;
}

string numConverter::convertB2D(string num)
{

  int result = 0;

  for (size_t i = 0; i < num.length(); i++)
  {
    if (num[i] != '0' && num[i] != '1')
    {
      return "ERROR: Invalid binary"; // <BREAK-ME>
    }

    if (num[i] == '1')
    {
      result += pow(2, (num.length() - i - 1));
    }
  }

  return std::to_string(result);
}

string numConverter::convertD2B(string num)
{
  int n = std::stoi(num);
  string result = "";
  while (n > 0)
  {
    result = std::to_string(n % 2) + result;
    n /= 2;
  }
  return result;
}

string numConverter::convertH2B(string num)
{
  string result = "";

  for (size_t i = 0; i < num.length(); i++)
  {
    if (hexToBin.find(num[i]) == hexToBin.end())
    {
      return "ERROR: Invalid binary";
    }
    result += hexToBin[num[i]];
  }
  return result;
}

string numConverter::convertB2H(string num)
{
  string result = "";

  while (num.length() % 4 != 0)
  {
    num = "0" + num;
  }

  for (size_t i = 0; i < num.length(); i += 4)
  {
    string temp = num.substr(i, 4);
    for (const auto &pair : hexToBin)
    {
      if (pair.second == temp)
      {
        result += pair.first;
      }
    }
  }
  return result;
}

bool numConverter::convert(string newType)
{

  if (newType == numConverter::type)
  {
    std::cerr << "ERROR: Number is already of type " << newType << std::endl;
    return false;
  }

  if (newType == "0b")
  {
    if (numConverter::type == "0d")
    {
      numConverter::type = newType;
      numConverter::num = convertD2B(num);
      return true;
    }
    else if (numConverter::type == "0x")
    {
      numConverter::type = newType;
      numConverter::num = convertH2B(num);
      return true;
    }
  }

  if (newType == "0d")
  {
    if (numConverter::type == "0b")
    {
      numConverter::type = newType;
      numConverter::num = convertB2D(num);
      return true;
    }
    else if (numConverter::type == "0x")
    {
      numConverter::type = newType;
      numConverter::num = convertB2D(convertH2B(num));
      return true;
    }
  }

  if (newType == "0x")
  {
    if (numConverter::type == "0b")
    {
      numConverter::type = newType;
      numConverter::num = convertB2H(num);
      return true;
    }
    else if (numConverter::type == "0d")
    {
      numConverter::type = newType;
      numConverter::num = convertB2H(convertD2B(num));
      return true;
    }
  }

  return false;
}
