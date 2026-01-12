# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat Parameterized constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat Copy constructor called" << std::endl;
    this->brain = new Brain(*obj.brain); // deep copy
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (!brain)
            brain = new Brain();
        *brain = *other.brain;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat makes a sound: Meow meow" << std::endl;
}

// Brain *Cat::getBrain(void) const
// {
// 	return (this->brain);
// }

void Cat::setIdea(int idx, const std::string& idea)
{
    brain->setIdea(idx, idea);
}

const std::string& Cat::getIdea(int idx) const
{
    return brain->getIdea(idx);
}