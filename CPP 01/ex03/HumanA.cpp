#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : name(name), w(w){}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->w.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "[HumanA] " << name << " destroyed" << std::endl;
}
