
#ifndef MODELPROGRAM_DECIMAL_H
#define MODELPROGRAM_DECIMAL_H


class Decimal : public Number {
private:
    int value;

public:
    Decimal(int val);
    std::string toBinary() const override;
    std::string toHexadecimal() const override;
    std::string toDecimal() const override;
};


#endif //MODELPROGRAM_DECIMAL_H
