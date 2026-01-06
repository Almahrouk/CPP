#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Unkown_clap_name"), ScavTrap(), FragTrap(), name("Unkown")
{
    hit_point = 100;      // FragTrap value
    energy_point = 50;    // ScavTrap value
    attack_damage = 30;   // FragTrap value

    std::cout << "Default DiamondTrap constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 30;

    std::cout << "DiamondTrap constructor called" << std::endl;
    // std::cout << "DiamondTrap values:"
    //           << " hit_points=" << hit_point
    //           << " energy_points=" << energy_point
    //           << " attack_damage=" << attack_damage
    //           << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    if (hit_point <= 0 || energy_point <= 0)
    {
        std::cout << "DiamondTrap " << name << " can't act (no hit points or energy points left)" << std::endl;
        return;
    }
    std::cout << "DiamondTrap " << name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
    energy_point--;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
