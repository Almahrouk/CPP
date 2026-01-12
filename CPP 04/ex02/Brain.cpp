# include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain Copy constructor called" << std::endl;
    *this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = obj.ideas[i];
        }
	}
	return (*this);
}

void Brain::setIdea(int idx, const std::string& idea) {
    if (idx < 0 || idx >= 100)
        return;
    ideas[idx] = idea;
}

const std::string& Brain::getIdea(int idx) const
{
    static const std::string empty = "";
    if (idx < 0 || idx >= 100)
        return empty;
    return ideas[idx];
}