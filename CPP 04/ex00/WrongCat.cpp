# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat Parameterized constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "\033[31m" << "WrongCat makes a sound: Meow meow" << "\033[0m" << std::endl;
}
