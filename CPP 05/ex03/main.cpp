#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

int main()
{
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

	return 0;
}