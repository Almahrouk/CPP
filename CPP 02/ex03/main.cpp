#include "Fixed.hpp"

int main( void )
{
    std::cout << "----- Step 1: Mandatory Test (from subject) -----" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    /*
    0
    0.00390625
    0.00390625
    0.00390625
    0.0078125
    10.1016
    10.1016
    */

    std::cout << "----- Step 2: Comparison operators -----" << std::endl;

    Fixed x(10);
    Fixed y(20);

    std::cout << "x < y : " << (x < y) << std::endl;
    std::cout << "x > y : " << (x > y) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;
    /*
    x < y : 1
    x > y : 0
    x <= y: 1
    x >= y: 0
    x == y: 0
    x != y: 1
    */

    std::cout << "----- Step 3: Arithmetic operators -----" << std::endl;
    Fixed A(10);
    Fixed B(3.5f);

    std::cout << "A + B = " << (A + B) << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
    std::cout << "A * B = " << (A * B) << std::endl;
    std::cout << "A / B = " << (A / B) << std::endl;
    /*
    a + b = 13.5
    a - b = 6.5
    a * b = 35
    a / b = 2.85714
    */


    std::cout << "----- Step 4: Increment/Decrement operators -----" << std::endl;
    Fixed n;

    std::cout << "n   = " << n << std::endl;
    std::cout << "++n = " << ++n << std::endl; // pre-increment
    std::cout << "n   = " << n << std::endl;
    std::cout << "n++ = " << n++ << std::endl; // post-increment
    std::cout << "n   = " << n << std::endl;

    std::cout << "--n = " << --n << std::endl; // pre-decrement
    std::cout << "n   = " << n << std::endl;
    std::cout << "n-- = " << n-- << std::endl; // post-decrement
    std::cout << "n   = " << n << std::endl;

    std::cout << "----- Step 5: min/max functions -----" << std::endl;
    Fixed u(42.5f);
    Fixed w(42.6f);

    std::cout << "min(u, w) = " << Fixed::min(u, w) << std::endl;
    std::cout << "max(u, w) = " << Fixed::max(u, w) << std::endl;

    Fixed const v(100);
    Fixed const vv(200);

    std::cout << "min(v, vv) = " << Fixed::min(v, vv) << std::endl;
    std::cout << "max(v, vv) = " << Fixed::max(v, vv) << std::endl;
    /*
    min(a, b) = 42.5
    max(a, b) = 42.6
    min(c, d) = 100
    max(c, d) = 200
    */
    std::cout << "---------------------END----------------------" << std::endl;

    return 0;
}