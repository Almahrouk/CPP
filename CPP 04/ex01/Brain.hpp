# ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
        std::string ideas[100];
		Brain();
		Brain(const Brain &obj);
		Brain &operator=(const Brain &obj);
		~Brain();

		void setIdea(int idx, const std::string& idea);
		const std::string& getIdea(int idx) const;
};

#endif