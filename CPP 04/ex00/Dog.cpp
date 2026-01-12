# include "Dog.hpp"

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(std::string type)
	: Animal(type)
{
	std::cout << "Dog Parameterized constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = obj;
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return (*this);
}

void Dog::makeSound() const
{
    std::cout << "\033[32m" << "Dog makes a sound: Woof woof" << "\033[0m" << std::endl;
}

