# ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"


class Dog : public Animal
{
	protected:
		std::string type;
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);
		~Dog();
		void makeSound() const;
		std::string getType() const;
};

#endif