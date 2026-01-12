# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
	: type(type)
{
	std::cout << "WrongAnimal Parameterized constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
	: type(obj.type)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "\033[31m" << "WrongAnimal makes a sound" << "\033[0m" <<  std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}