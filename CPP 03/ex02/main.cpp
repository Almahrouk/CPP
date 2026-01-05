#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "----- Creating Robots -----" << std::endl;
    
    ClapTrap clap("CL4P-TP");
    FragTrap frag("FR4G-TP");

    std::cout << "\n----- Basic Attacks -----" << std::endl;
    clap.attack("Enemy1");
    frag.attack("Enemy2");

    std::cout << "\n----- Special Ability -----" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n----- Taking Damage -----" << std::endl;
    clap.takeDamage(40);
    frag.takeDamage(50);

    std::cout << "\n----- Repairing -----" << std::endl;
    clap.beRepaired(20);
    frag.beRepaired(30);

    std::cout << "\n----- Exhaust Energy -----" << std::endl;
    for (int i = 0; i < 105; i++)  // frag has 100 energy points
        frag.attack("Bandit");

    std::cout << "\n----- Copy Test -----" << std::endl;
    FragTrap fragCopy(frag);
    fragCopy.attack("Enemy3");
    fragCopy.highFivesGuys();

    std::cout << "\n----- Assignment Test -----" << std::endl;
    FragTrap fragAssigned;
    fragAssigned = frag;
    fragAssigned.attack("Enemy4");
    fragAssigned.highFivesGuys();

    std::cout << "\n----- End of Scope (Destruction) -----" << std::endl;
    return 0;
}
