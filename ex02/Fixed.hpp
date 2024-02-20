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

    bool    operator>(const Fixed &other) const;
    bool    operator<(const Fixed &other) const;
    bool    operator>=(const Fixed &other) const;
    bool    operator<=(const Fixed &other) const;
    bool    operator==(const Fixed &other) const;
    bool    operator!=(const Fixed &other) const;

    float   operator+(const Fixed &other) const;
    float   operator-(const Fixed &other) const;
    float   operator*(const Fixed &other) const;
    float   operator/(const Fixed &other) const;

    Fixed   operator++(int);
    Fixed   operator++();
    Fixed   operator--(int);
    Fixed   operator--();


    float   toFloat(void) const;
    int     toInt(void) const;

    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    Fixed &operator=(const Fixed &src);

    ~Fixed();

private:
    int value;
    static const int fractionalBits = 8;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);