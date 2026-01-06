#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unknown")
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hit_point <= 0 || energy_point <= 0)
    {
        std::cout << "ScavTrap " << name << " can't act (no hit points or energy points left)" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
    energy_point--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}