# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat Parameterized constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = obj;
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void Cat::makeSound() const
{
    std::cout << "\033[32m" << "Cat makes a sound: Meow meow" << "\033[0m" << std::endl;
}

