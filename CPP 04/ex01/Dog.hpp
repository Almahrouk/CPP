# ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"


class Dog : public Animal
{
	protected:
		std::string type;
		Brain* brain;
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);
		~Dog();
		void makeSound() const;
		std::string getType() const;
		void setIdea(int index, const std::string &idea);
		const std::string& getIdea(int idx) const;
};

#endif