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
};

std::ostream & operator<<(std::ostream &out, const Fixed &obj);

#endif