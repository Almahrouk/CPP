#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "A zombie is born!" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "A zombie is born!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed!" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

