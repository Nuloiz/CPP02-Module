#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
public:

    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int param);
    Fixed(const float param);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    float   toFloat(void) const;
    int     toInt(void) const;

    Fixed &operator=(const Fixed &other);

    ~Fixed();

private:
    int value;
    static const int fractionalBits = 8;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);