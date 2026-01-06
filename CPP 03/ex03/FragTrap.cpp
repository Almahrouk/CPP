#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unknown")
{
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;
    std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (hit_point <= 0 || energy_point <= 0)
    {
        std::cout << "FragTrap " << name << " can't act (no hit points or energy points left)" << std::endl;
        return;
    }
    std::cout << "FragTrap " << name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
    energy_point--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " a positive high-fives request." << std::endl;
}