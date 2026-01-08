#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	// std::cout << meta->getType() << std::endl; // Animal
	// meta->makeSound(); // Animal sound
	// delete meta;
	// const Animal* i = new Cat();
	// std::cout << i->getType() << std::endl; // Cat
	// i->makeSound(); // Meow
	// delete i;
	const Animal* j = new Dog();
	std::cout << j->getType() << std::endl; // Dog
	j->makeSound(); // Woof
	delete j;
	return 0;
}
