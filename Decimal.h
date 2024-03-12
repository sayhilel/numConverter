
#ifndef MODELPROGRAM_DECIMAL_H
#define MODELPROGRAM_DECIMAL_H

using namespace std;

class Decimal : public Number {
private:
    int value;

public:
    Decimal(int val);
    string toBinary() const override;
    string toHexadecimal() const override;
    string toDecimal() const override;
};


#endif //MODELPROGRAM_DECIMAL_H
