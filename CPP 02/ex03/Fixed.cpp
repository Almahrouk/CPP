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

bool operator>(const Fixed &a, const Fixed &b)
{
    return a.getRawBits() > b.getRawBits();
}
bool operator<(const Fixed &a, const Fixed &b)
{
    return a.getRawBits() < b.getRawBits();
}
bool operator>=(const Fixed &a, const Fixed &b)
{
    return a.getRawBits() >= b.getRawBits();
}
bool operator<=(const Fixed &a, const Fixed &b)
{
    return a.getRawBits() <= b.getRawBits();
}
bool operator==(const Fixed &a, const Fixed &b)
{
    return a.getRawBits() == b.getRawBits();
}
bool operator!=(const Fixed &a, const Fixed &b)
{
    return a.getRawBits() != b.getRawBits();
}

Fixed &operator+(const Fixed &a, const Fixed &b)
{
    Fixed *result = new Fixed();
    result->setRawBits(a.getRawBits() + b.getRawBits());
    return *result;
}
Fixed &operator-(const Fixed &a, const Fixed &b)
{
    Fixed *result = new Fixed();
    result->setRawBits(a.getRawBits() - b.getRawBits());
    return *result;
}
Fixed &operator*(const Fixed &a, const Fixed &b)
{
    Fixed *result = new Fixed();
    long temp = (long)a.getRawBits() * (long)b.getRawBits();
    result->setRawBits(temp >> Fixed::fractionalBits);
    return *result;
}
Fixed &operator/(const Fixed &a, const Fixed &b)
{
    if (b.getRawBits() == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        exit(1);
    }
    Fixed *result = new Fixed();
    long temp = ((long)a.getRawBits() << Fixed::fractionalBits) / (long)b.getRawBits();
    result->setRawBits(temp);
    return *result;
}

Fixed &operator++(Fixed &a)
{
    a.setRawBits(a.getRawBits() + 1);
    return a;
}
Fixed operator++(Fixed &a, int)
{
    Fixed temp = a;
    a.setRawBits(a.getRawBits() + 1);
    return temp;
}
Fixed &operator--(Fixed &a)
{
    a.setRawBits(a.getRawBits() - 1);
    return a;
}
Fixed operator--(Fixed &a, int)
{
    Fixed temp = a;
    a.setRawBits(a.getRawBits() - 1);
    return temp;
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
std::ostream &operator<<(std::ostream &cout, const Fixed &obj)
{
    cout << obj.toFloat();
    return cout;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}


/*
std::cout << 42 calls std::cout.operator<<(42)

Given std::string s;, s = "abc"; calls s.operator=("abc")
Given std::map<int, int> m;, m[1] = 2; calls m.operator[](1)

std::string str = "Hello, ";
str.operator+=("world");                      // same as str += "world";
operator<<(operator<<(std::cout, str), '\n'); // same as std::cout << str << '\n';
*/