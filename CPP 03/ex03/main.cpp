#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

int main()
{
    DiamondTrap d("123");
    
    std::cout << d.FragTrap::ClapTrap::getName() << std::endl;    

    return 0;
}
