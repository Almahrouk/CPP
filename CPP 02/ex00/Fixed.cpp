#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) : value(obj.value)
{
    std::cout << "Copy constructor called" << std::endl;
    // *this = obj;

}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->value = obj.getRawBits();
    std::cout << std::endl;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called ";
    return (this->value);
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}
// Fixed::Fixed(const int num)
// {
//     std::cout << "Int constructor called" << std::endl;
//     this->value = num << fractionalBits;
// }