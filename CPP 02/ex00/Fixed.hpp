#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        // static const int fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &obj);
        Fixed & operator=(const Fixed &obj);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
#endif