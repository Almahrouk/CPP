#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "----- Creating Robots -----" << std::endl;
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");

    std::cout << "\n----- Basic Attacks -----" << std::endl;
    clap.attack("Enemy1");
    scav.attack("Enemy2");

    std::cout << "\n----- Special Ability -----" << std::endl;
    scav.guardGate();

    std::cout << "\n----- Taking Damage -----" << std::endl;
    clap.takeDamage(30);
    scav.takeDamage(50);

    std::cout << "\n----- Repairing -----" << std::endl;
    clap.beRepaired(20);
    scav.beRepaired(30);

    std::cout << "\n----- Exhaust Energy -----" << std::endl;
    for (int i = 0; i < 55; i++)  // try to exhaust energy points
        scav.attack("Bandit");

    std::cout << "\n----- Copy Test -----" << std::endl;
    ScavTrap scavCopy(scav);
    scavCopy.attack("Enemy3");
    scavCopy.guardGate();

    std::cout << "\n----- Assignment Test -----" << std::endl;
    ScavTrap scavAssigned;
    scavAssigned = scav;
    scavAssigned.attack("Enemy4");
    scavAssigned.guardGate();

    std::cout << "\n----- End of Scope (Destruction) -----" << std::endl;
    return 0;
}
