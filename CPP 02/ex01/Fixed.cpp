#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->value = obj.getRawBits();
    return (*this);
}

Fixed::Fixed(int const num)
{
    std::cout << "Int constructor called" << std::endl;
    value = num << fractionalBits;  // store as fixed-point
}

Fixed::Fixed(float const num)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(num * (1 << fractionalBits));
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

float Fixed::toFloat(void) const {
    return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return value >> fractionalBits;
}

// Non-member operator<<
std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return out;
}