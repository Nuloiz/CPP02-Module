#pragma once

#include <iostream>
#include <string>

class Fixed{
public:

    Fixed();

    Fixed(const Fixed &other);

    ~Fixed();

    Fixed &operator=(const Fixed &other);

private:
    int _value;
    static const int _fractionalBits = 8;
};