#include "HumanA.hpp"

HumanA::HumanA()
{

}

HumanA::HumanA(std::string name, Weapon &w)
{
    // std::cout << "[HumanA] " << name << " constructed with weapon: " << w.getType() << std::endl;
    this->name = name;
    this->w = &w;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->w->getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "[HumanA] " << name << " destroyed" << std::endl;
}
