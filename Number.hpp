//
// Created by jayaa on 3/11/2024.
//

#ifndef MODELPROGRAM_NUMBER_H
#define MODELPROGRAM_NUMBER_H

#include <string>

using namespace std;

class Number {
public:
    virtual ~Number() {}

    virtual string toBinary() const = 0;

    virtual string toHexadecimal() const = 0;

    virtual string toDecimal() const = 0;
};


#endif //MODELPROGRAM_NUMBER_H
