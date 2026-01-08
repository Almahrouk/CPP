# include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string type) : AAnimal(type)
{
	std::cout << "Dog Parameterized constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog &obj) : AAnimal(obj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain(*obj.brain); // deep copy
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);

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

std::string Dog::getType() const
{
    return (this->type);
}

void Dog::setIdea(int idx, const std::string& idea) {
    if (!brain || idx < 0 || idx >= 100)
        return;
    brain->ideas[idx] = idea;
}

const std::string& Dog::getIdea(int idx) const
{
    static const std::string empty = "";
    if (!brain || idx < 0 || idx >= 100)
        return empty;
    return brain->ideas[idx];
}
