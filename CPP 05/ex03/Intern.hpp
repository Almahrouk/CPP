#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);
		AForm *makeForm(const std::string form_str, const std::string target);
};
#endif