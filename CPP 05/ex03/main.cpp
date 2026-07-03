#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

static void separator(const std::string & title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	/* 1. The example given in the subject */
	separator("Subject example: makeForm(\"robotomy request\", \"Bender\")");
	{
		Intern someRandomIntern;
		AForm * rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf != NULL)
		{
			std::cout << "---- OK ----" << std::endl;
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}

	/* 2. Making each of the three known form types */
	separator("makeForm() for each known form type");
	{
		Intern intern;
		AForm * shrub = intern.makeForm("shrubbery creation", "backyard");
		AForm * robot = intern.makeForm("robotomy request", "Marvin");
		AForm * pardon = intern.makeForm("presidential pardon", "Trillian");

		if (shrub)
			std::cout << *shrub << std::endl;
		if (robot)
			std::cout << *robot << std::endl;
		if (pardon)
			std::cout << *pardon << std::endl;

		delete shrub;
		delete robot;
		delete pardon;
	}

	/* 3. Unknown form name -> explicit error message, returns NULL */
	separator("makeForm() with an unknown form name");
	{
		Intern intern;
		AForm * bogus = intern.makeForm("time travel request", "Marty");
		if (bogus == NULL)
			std::cout << "makeForm() correctly returned NULL" << std::endl;
		else
		{
			std::cout << "ERROR: expected NULL but got a form!" << std::endl;
			delete bogus;
		}
	}

	/* 4. Full workflow: intern builds a form, a bureaucrat signs and executes it */
	separator("Full workflow: Intern builds, Bureaucrat signs and executes");
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);

		AForm * pardon = intern.makeForm("presidential pardon", "Marvin");
		if (pardon != NULL)
		{
			boss.signForm(*pardon);
			boss.executeForm(*pardon);
			delete pardon;
		}
	}

	/* 5. Intern builds a ShrubberyCreationForm and it actually creates the file */
	separator("Intern-built ShrubberyCreationForm actually plants shrubbery");
	{
		Intern intern;
		Bureaucrat gardener("Gardener", 100);

		AForm * shrub = intern.makeForm("shrubbery creation", "porch");
		if (shrub != NULL)
		{
			gardener.signForm(*shrub);
			gardener.executeForm(*shrub);
			delete shrub;

			std::ifstream check("porch_shrubbery");
			if (check.is_open())
				std::cout << "File 'porch_shrubbery' was created successfully." << std::endl;
			else
				std::cout << "File 'porch_shrubbery' was NOT created!" << std::endl;
		}
	}

	/* 6. Copy constructor / assignment operator for Intern (no state, but OCF is required) */
	separator("Intern copy constructor + assignment operator");
	{
		Intern original;
		Intern copy(original);
		Intern assigned;
		assigned = original;

		AForm * f1 = copy.makeForm("robotomy request", "CopyTarget");
		AForm * f2 = assigned.makeForm("presidential pardon", "AssignedTarget");
		if (f1)
			delete f1;
		if (f2)
			delete f2;
	}

	return 0;
}