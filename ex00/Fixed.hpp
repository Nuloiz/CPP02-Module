#pragma once

#include <iostream>
#include <string>

class Fixed{
public:

    Fixed();

    Fixed(const Fixed &other);

    int getRawBits(void) const;
    int setRawBits(int const raw);

    Fixed &operator = (const Fixed &other);

    ~Fixed();



private:
    int _value;
    static const int _fractionalBits = 8;
};