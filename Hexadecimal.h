
#ifndef MODELPROGRAM_HEXADECIMAL_H
#define MODELPROGRAM_HEXADECIMAL_H

using namespace std;

class Hexadecimal : public Number {
private:
    string value;

public:
    Hexadecimal(const std::string& val);
    string toBinary() const override;
    string toDecimal() const override;
    string toHexadecimal() const override;
};


#endif //MODELPROGRAM_HEXADECIMAL_H
