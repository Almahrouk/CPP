# include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("Unknown"), hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
	: name(obj.name),
		hit_point(obj.hit_point),
		energy_point(obj.energy_point),
		attack_damage(obj.attack_damage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hit_point = obj.hit_point;
		this->energy_point = obj.energy_point;
		this->attack_damage = obj.attack_damage;
	}
	return (*this);
}

std::string ClapTrap::getName(void) const
{
	return this->name;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hit_point <= 0 || this->energy_point <= 0)
	{
		std::cout << "ClapTrap " << name << " can't act (no hit points or energy points left)" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	this->energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount
				<< " points of damage!" << std::endl;
	if (hit_point <= amount)
		hit_point = 0;
	else
		hit_point -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hit_point || !this->energy_point)
	{
		std::cout << "ClapTrap can't do anything if it has no hit points or energy points left." << std::endl;
		return ;
	}
	this->hit_point += amount;
	std::cout << "be Repaired is called, hit_point new = " << hit_point << std::endl;
	this->energy_point--;
}