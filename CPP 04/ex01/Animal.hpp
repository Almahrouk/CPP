# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &obj);
		Animal &operator=(const Animal &obj);
		~Animal();
		std::string getType() const;
		void makeSound() const;
};

#endif