#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		// Orthodox Canonical Form
		Intern();
		Intern(const Intern & other);
		Intern & operator=(const Intern & other);
		~Intern();

		// Builds an AForm* by name, targeted at the given string.
		// Prints "Intern creates <form>" on success, or an explicit
		// error message if the form name is unknown.
		AForm *	makeForm(const std::string & formName, const std::string & target) const;

	private:
		// One entry of the lookup table: a form name paired with the
		// static function able to build that concrete form.
		typedef AForm * (*FormBuilder)(const std::string & target);

		struct FormEntry
		{
			std::string	name;
			FormBuilder	builder;
		};

		// Concrete builder functions (one per known form type).
		static AForm *	buildShrubberyCreationForm(const std::string & target);
		static AForm *	buildRobotomyRequestForm(const std::string & target);
		static AForm *	buildPresidentialPardonForm(const std::string & target);

		// The lookup table itself and its size, used by makeForm() to
		// find the right builder without an if/else if/else chain.
		static const FormEntry	_formTable[];
		static const int		_formTableSize;
};

#endif