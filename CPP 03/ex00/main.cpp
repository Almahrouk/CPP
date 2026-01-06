#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Alpha");
	a.attack("Target 1");
	a.takeDamage(5);
	a.beRepaired(3);
	a.attack("Target 1");
    
    std::cout << "********************************" << std::endl;
    
	ClapTrap b;
	b.attack("Target 2");
	b.takeDamage(70);
	b.takeDamage(70);
	b.beRepaired(2);
	b.attack("Target 2");

    std::cout << "********************************" << std::endl;
    
	ClapTrap *c = new ClapTrap();
	c->attack("Target 3");
	c->takeDamage(1);
	c->beRepaired(9);
	c->attack("Target 3");
    delete c;

    std::cout << "********************************" << std::endl;
    
	ClapTrap *d = new ClapTrap(a);
	d->attack("Target 4");
	d->takeDamage(6);
	d->beRepaired(4);
	d->attack("Target 4");
    delete d;

    return 0;
}
