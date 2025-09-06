#include "Weapon.hpp"

Weapon::Weapon()
{
    std::cout << "[Weapon] Default constructor called" << std::endl;
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

std::string Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    std::cout << "[Weapon] Destroyed (type was: " << type << ")" << std::endl;
}
