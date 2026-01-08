# include "Animal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal Parameterized constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj) : type(obj.type)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return (*this);
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal makes a sound" << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->type);
}
