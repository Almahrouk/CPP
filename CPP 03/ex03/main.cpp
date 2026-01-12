#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

int main()
{
    DiamondTrap d("123");
    
    std::cout << d.ClapTrap::getName() << std::endl;    
    d.whoAmI();

    return 0;
}
