#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Default constructor called" << std::endl;
    hit_point = 10;
    energy_point = 10;
    attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    // if (this != &obj)
    //     this->name = obj.getName();
    return (*this);
}

// std::string ClapTrap::getName(void)
// {
//     return this->name;
// }

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << 10 << " points of damage!" << std::endl;
    hit_point -= attack_damage;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    hit_point -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (!hit_point || !energy_point)
    {
        std::cout << "ClapTrap can't do anything if it has no hit points or energy points left." << std::endl;
        return;
    }
    hit_point += amount;
    energy_point--;
}