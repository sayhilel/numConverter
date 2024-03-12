//
// Created by jayaa on 3/11/2024.
//

#ifndef MODELPROGRAM_HEXADECIMAL_H
#define MODELPROGRAM_HEXADECIMAL_H


class Hexadecimal : public Number {
private:
    std::string value;

public:
    Hexadecimal(const std::string& val);
    std::string toBinary() const override;
    std::string toDecimal() const override;
    std::string toHexadecimal() const override;
};


#endif //MODELPROGRAM_HEXADECIMAL_H
