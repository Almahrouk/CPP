#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        std::cout << "=============Iteration " << i << ":=================" << std::endl;
        Base *base = generate();
        std::cout << "Pointer: ";
        identify(base);
        std::cout << "Reference: ";
        identify(*base);
        delete base;
    }

    return 0;
}
