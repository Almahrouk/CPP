#include "HumanB.hpp"

HumanB::HumanB()
{

}

HumanB::HumanB(std::string name)
{
    // std::cout << "[HumanB] " << name << " constructed (no weapon yet)" << std::endl;
    this->name = name;
    this->w = NULL;
}

void HumanB::setWeapon(Weapon &w)
{
    this->w = &w;
}

void HumanB::attack()
{
    if (w)
        std::cout << name << " attacks with their " << w->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}


HumanB::~HumanB()
{
    std::cout << "[HumanB] " << name << " destroyed" << std::endl;
}

// void HumanB::attack()
// {
//     std::cout << name << " attacks with their " << type << std::endl;
// }