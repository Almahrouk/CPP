#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(int const num);
        Fixed(float const num);
        ~Fixed();
        Fixed(const Fixed &obj);
        Fixed & operator=(const Fixed &obj);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

        friend Fixed &operator*(const Fixed& a, const Fixed& b);
        friend Fixed &operator/(const Fixed& a, const Fixed& b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

bool operator>(const Fixed &a, const Fixed &b);
bool operator<(const Fixed &a, const Fixed &b);
bool operator>=(const Fixed &a, const Fixed &b);
bool operator<=(const Fixed &a, const Fixed &b);
bool operator==(const Fixed &a, const Fixed &b);
bool operator!=(const Fixed &a, const Fixed &b);

Fixed &operator+(const Fixed &a, const Fixed &b);
Fixed &operator-(const Fixed &a, const Fixed &b);
// Fixed &operator*(const Fixed &a, const Fixed &b);
// Fixed &operator/(const Fixed &a, const Fixed &b);

Fixed &operator++(Fixed &a);       // Prefix increment
Fixed operator++(Fixed &a, int);    // Postfix increment
Fixed &operator--(Fixed &a);       // Prefix decrement
Fixed operator--(Fixed &a, int);    // Postfix decrement

#endif