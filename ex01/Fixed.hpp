#pragma once

#include <iostream>
#include <string>

class Fixed{
public:

    Fixed();

    Fixed(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed &operator=(const Fixed &other);

    ~Fixed();

private:
    int value;
    static const int fractionalBits = 8;
};