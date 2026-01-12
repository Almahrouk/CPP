# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog Parameterized constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain(*obj.brain); // deep copy
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);

        // deep copy
        if (!brain)
            brain = new Brain();
        *brain = *other.brain;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog makes a sound: Woof woof" << std::endl;
}

// Brain *Dog::getBrain(void) const
// {
// 	return (this->brain);
// }

void Dog::setIdea(int idx, const std::string& idea)
{
    brain->setIdea(idx, idea);
}

const std::string& Dog::getIdea(int idx) const
{
    return brain->getIdea(idx);
}
