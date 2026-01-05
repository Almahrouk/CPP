#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alpha");

    a.attack("Target");
    a.takeDamage(5);
    a.beRepaired(3);
    a.attack("Target");

    return 0;
}
