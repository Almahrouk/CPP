#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* ---------------------- Orthodox Canonical Form ------------------------- */

Intern::Intern()
{
	return;
}

Intern::Intern(const Intern & other)
{
	(void)other; // Intern has no attributes, nothing to copy
	return;
}

Intern & Intern::operator=(const Intern & other)
{
	(void)other; // Intern has no attributes, nothing to assign
	return (*this);
}

Intern::~Intern()
{
	return;
}

/* --------------------------- Concrete builders ------------------------------ */

AForm * Intern::buildShrubberyCreationForm(const std::string & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm * Intern::buildRobotomyRequestForm(const std::string & target)
{
	return (new RobotomyRequestForm(target));
}

AForm * Intern::buildPresidentialPardonForm(const std::string & target)
{
	return (new PresidentialPardonForm(target));
}

/* ------------------------------ Lookup table --------------------------------- */

const Intern::FormEntry Intern::_formTable[] =
{
	{ "shrubbery creation", &Intern::buildShrubberyCreationForm },
	{ "robotomy request",   &Intern::buildRobotomyRequestForm },
	{ "presidential pardon", &Intern::buildPresidentialPardonForm }
};

const int Intern::_formTableSize = sizeof(Intern::_formTable) / sizeof(Intern::_formTable[0]);

/* -------------------------------- makeForm ----------------------------------- */

AForm * Intern::makeForm(const std::string & formName, const std::string & target) const
{
	for (int i = 0; i < _formTableSize; i++)
	{
		if (_formTable[i].name == formName)
		{
			AForm * form = _formTable[i].builder(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Intern: unknown form name \"" << formName << "\"" << std::endl;
	return (NULL);
}