#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *z;
    int i;

    z = new Zombie[N];
    i = 0;
    while(i < N)
    {
        z[i].setName(name);
        i++;
    }
    i = 0;
    while(i < N)
    {
        z[i].announce();
        i++;
    }
    return z;
}