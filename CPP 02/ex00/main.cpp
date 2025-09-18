#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
// int main()
// {
//     Fixed a;
//     Fixed b( a );
//     Fixed c;
//     c = b;

//     std::cout << "-----------------Get-----------------" << std::endl;
//     std::cout << a.getRawBits() << std::endl;
//     std::cout << b.getRawBits() << std::endl;
//     std::cout << c.getRawBits() << std::endl;


//     std::cout << "-----------------Set-----------------" << std::endl;
//     a.setRawBits(1);
//     b.setRawBits(2);
//     c.setRawBits(3);

//     std::cout << "-----------------Get-----------------" << std::endl;
//     std::cout << a.getRawBits() << std::endl;
//     std::cout << b.getRawBits() << std::endl;
//     std::cout << c.getRawBits() << std::endl;

//     std::cout << "-----------------End-----------------" << std::endl;
//     return 0;
// }