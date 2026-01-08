# ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	protected:
		std::string type;
		Brain* brain;
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &obj);
		Cat &operator=(const Cat &obj);
		~Cat();
		void makeSound() const;
		std::string getType() const;
		void setIdea(int index, const std::string &idea);
		const std::string& getIdea(int idx) const;
};

#endif