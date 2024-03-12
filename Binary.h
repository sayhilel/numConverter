
#ifndef MODELPROGRAM_BINARY_H
#define MODELPROGRAM_BINARY_H


class Binary : public Number {
private:
    std::string value;

public:
    Binary(const std::string& val);
    std::string toBinary() const override;
    std::string toDecimal() const override;
    std::string toHexadecimal() const override;
};


#endif //MODELPROGRAM_BINARY_H
