#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern Deconstructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

static AForm	*makePresidentForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobotForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string form_str, const std::string target)
{
	AForm *(*all_forms_fun[])(const std::string target) = {&makePresidentForm, &makeRobotForm, &makeShrubberyForm};
	std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (form_str == forms[i])
		{
			std::cout << "Intern creates " << form_str << " now" << std::endl;
			return (all_forms_fun[i](target));
		}
	}

	std::cout << "Intern can not create a form called " << form_str << std::endl;
	return (NULL);
}