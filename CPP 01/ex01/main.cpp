#include "Zombie.hpp"

int main()
{
    Zombie* z = zombieHorde(5, "HeapZombie");
    delete[] z;
    return 0;
}