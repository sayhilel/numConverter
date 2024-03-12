
#ifndef MODELPROGRAM_BINARY_H
#define MODELPROGRAM_BINARY_H

using namespace std;

class Binary : public Number {
private:
    string value;

public:
    Binary(const std::string& val);
    string toBinary() const override;
    string toDecimal() const override;
    string toHexadecimal() const override;
};


#endif //MODELPROGRAM_BINARY_H
