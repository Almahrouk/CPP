#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

int main()
{
	ShrubberyCreationForm defaultShrub;
	RobotomyRequestForm defaultRobot;
	PresidentialPardonForm defaultPardon;
	std::cout << defaultShrub << std::endl;
	std::cout << defaultRobot << std::endl;
	std::cout << defaultPardon << std::endl;


	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Marvin");
	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	{
		Bureaucrat president("President", 1);
		try
		{
			shrub.execute(president);
		}
		catch (std::exception & e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
	}

	{
		Bureaucrat gardener("Gardener", 100); // grade 100 <= 137, can both sign and execute
		shrub.beSigned(gardener);
		gardener.executeForm(shrub);

		std::ifstream check("garden_shrubbery");
		if (check.is_open())
		{
			std::cout << "File 'garden_shrubbery' was created successfully. Contents:" << std::endl;
			std::string line;
			while (std::getline(check, line))
				std::cout << line << std::endl;
			check.close();
		}
		else
			std::cout << "File 'garden_shrubbery' was NOT created!" << std::endl;
	}

	return 0;
}