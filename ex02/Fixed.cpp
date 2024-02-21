#include "Fixed.hpp"

Fixed::Fixed() :    value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed & Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    value = other.value;
    return (*this);
}

Fixed::Fixed(const int param) {
    std::cout << "Int constructor called" << std::endl;
    value = param << fractionalBits;
}

Fixed::Fixed(const float param) {
    std::cout << "Float constructor called" << std::endl;
    value = (int)roundf(param * (1 << fractionalBits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

float Fixed::toFloat() const {
    return ((float)value / (1 << fractionalBits));
}

int Fixed::toInt() const {
    return (value >> fractionalBits);
}

bool    Fixed::operator>(const Fixed &other) const {
    return (value > other.value);
}

bool    Fixed::operator<(const Fixed &other) const {
    return (value < other.value);
}

bool    Fixed::operator>=(const Fixed &other) const {
    return (value >= other.value);
}

bool    Fixed::operator<=(const Fixed &other) const {
    return (value <= other.value);
}

bool    Fixed::operator==(const Fixed &other) const {
    return (value == other.value);
}

bool    Fixed::operator!=(const Fixed &other) const {
    return (value != other.value);
}

float   Fixed::operator+(const Fixed &other) const {
    return (toFloat() + other.toFloat());
}

float   Fixed::operator-(const Fixed &other) const {
    return (toFloat() - other.toFloat());
}

float   Fixed::operator*(const Fixed &other) const {
    return (toFloat() * other.toFloat());
}

float   Fixed::operator/(const Fixed &other) const {
    return (toFloat() / other.toFloat());
}

Fixed   Fixed::operator++(int) {
    Fixed tmp(*this);
    value++;
    return (tmp);
}

Fixed   Fixed::operator++() {
    value++;
    return (*this);
}

Fixed   Fixed::operator--(int) {
    Fixed tmp(*this);
    value--;
    return (tmp);
}

Fixed   Fixed::operator--() {
    value--;
    return (*this);
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return (a);
    return (b);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}