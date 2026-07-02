#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

static void separator(const std::string & title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	/* Note: AForm is abstract (execute() calls the pure virtual executeAction()),
	 * so "AForm form;" would fail to compile. That's expected and not tested here. */

	/* 1. Default construction + insertion operator for each concrete form */
	separator("Default construction of the three concrete forms");
	ShrubberyCreationForm defaultShrub;
	RobotomyRequestForm defaultRobot;
	PresidentialPardonForm defaultPardon;
	std::cout << defaultShrub << std::endl;
	std::cout << defaultRobot << std::endl;
	std::cout << defaultPardon << std::endl;

	/* 2. Parameterized construction + correct hard-coded grades */
	separator("Parameterized construction + required grades");
	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Marvin");
	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	/* 3. execute() before signing -> FormNotSignedException */
	separator("execute() before signing (should fail)");
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

	/* 4. beSigned() then execute() with insufficient executor grade -> GradeTooLowException */
	separator("execute() with grade too low after signing (should fail)");
	{
		Bureaucrat highEnoughToSign("Signer", 100);   // <= 145, can sign
		Bureaucrat tooLowToExecute("Grunt", 140);     // > 137, cannot execute
		try
		{
			shrub.beSigned(highEnoughToSign);
			std::cout << "After signing: " << shrub << std::endl;
			shrub.execute(tooLowToExecute);
		}
		catch (std::exception & e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
	}

	/* 5. Full success path: ShrubberyCreationForm creates a file */
	separator("ShrubberyCreationForm full success (writes a file)");
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

	/* 6. Full success path: RobotomyRequestForm (run a few times to show both outcomes) */
	separator("RobotomyRequestForm full success (50/50 outcome, run 4 times)");
	{
		Bureaucrat technician("Technician", 40); // grade 40 <= 45, can both sign and execute
		for (int i = 0; i < 4; i++)
		{
			RobotomyRequestForm attempt("TestSubject");
			attempt.beSigned(technician);
			technician.executeForm(attempt);
		}
	}

	/* 7. Full success path: PresidentialPardonForm */
	separator("PresidentialPardonForm full success");
	{
		Bureaucrat president("President", 1); // grade 1, satisfies everything
		pardon.beSigned(president);
		president.executeForm(pardon);
	}

	/* 8. Bureaucrat::executeForm() failure messages (not signed, grade too low) */
	separator("Bureaucrat::executeForm() failure messages");
	{
		Bureaucrat lowGrade("Clerk", 150);
		RobotomyRequestForm unsignedForm("Someone");
		lowGrade.executeForm(unsignedForm); // not signed

		Bureaucrat midGrade("Officer", 60); // can sign (<=72) but not execute (>45)
		RobotomyRequestForm signedForm("SomeoneElse");
		midGrade.signForm(signedForm);
		midGrade.executeForm(signedForm); // signed, but grade too low to execute
	}

	/* 9. Polymorphism: store different concrete forms as AForm* and execute them uniformly */
	separator("Polymorphism via AForm* / AForm&");
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm f1("office");
		RobotomyRequestForm f2("Robby");
		PresidentialPardonForm f3("Trillian");

		std::vector<AForm *> forms;
		forms.push_back(&f1);
		forms.push_back(&f2);
		forms.push_back(&f3);

		for (std::vector<AForm *>::iterator it = forms.begin(); it != forms.end(); ++it)
		{
			boss.signForm(**it);
			boss.executeForm(**it); // calls the right executeAction() via virtual dispatch
		}
	}

	return 0;
}