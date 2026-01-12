#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	// const Animal* meta = new Animal();
// 	// std::cout << meta->getType() << std::endl; // Animal
// 	// meta->makeSound(); // Animal sound
// 	// delete meta;
// 	// const Animal* i = new Cat();
// 	// std::cout << i->getType() << std::endl; // Cat
// 	// i->makeSound(); // Meow
// 	// delete i;
// 	const Animal* j = new Dog();
// 	std::cout << j->getType() << std::endl; // Dog
// 	j->makeSound(); // Woof
// 	delete j;
// 	return 0;
// }

int	main() {
	WrongAnimal	*unknown = new WrongAnimal();
	std::cout << unknown->getType() << " " << std::endl;
	unknown->makeSound();
	delete unknown;
	
	std::cout << "*************************\n";

	Dog		*dog = new Dog();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	delete dog;

	std::cout << "*************************\n";

	unknown = new WrongCat();
	unknown->makeSound();
	delete unknown;
	return 0;
}
