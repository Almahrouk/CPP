#include "Bureaucrat.hpp"
#include "Form.hpp"

static void separator(const std::string & title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	/* 1. Default construction + insertion operator for Form */
	separator("Form default constructor + operator<<");
	Form defaultForm;
	std::cout << defaultForm << std::endl;

	/* 2. Valid Form construction + getters */
	separator("Valid Form construction + getters");
	try
	{
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm << std::endl;
		std::cout << "getName(): " << taxForm.getName() << std::endl;
		std::cout << "getIsSigned(): " << taxForm.getIsSigned() << std::endl;
		std::cout << "getRequiredSignGrade(): " << taxForm.getRequiredSignGrade() << std::endl;
		std::cout << "getRequiredExecuteGrade(): " << taxForm.getRequiredExecuteGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 3. Form construction at boundaries (1 and 150) should succeed */
	separator("Form boundary construction (grade 1 and grade 150)");
	try
	{
		Form topForm("Top Secret Form", 1, 1);
		std::cout << topForm << std::endl;
		Form bottomForm("Trivial Form", 150, 150);
		std::cout << bottomForm << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 4. Form construction with a grade too high (< 1) throws GradeTooHighException */
	separator("Form grade too high (gradeToSign = 0)");
	try
	{
		Form badForm("Impossible Form", 0, 10);
		std::cout << badForm << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	/* 5. Form construction with a grade too low (> 150) throws GradeTooLowException */
	separator("Form grade too low (gradeToExecute = 151)");
	try
	{
		Form badForm("Overreaching Form", 10, 151);
		std::cout << badForm << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	/* 6. beSigned() - bureaucrat's grade is high enough (equal to required) */
	separator("beSigned() success (grade == required)");
	try
	{
		Bureaucrat manager("Manager", 25);
		Form form("Purchase Order", 25, 25);
		std::cout << form << std::endl;
		form.beSigned(manager);
		std::cout << "After beSigned(): " << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 7. beSigned() - bureaucrat's grade is too low, must throw */
	separator("beSigned() failure (grade too low)");
	{
		Bureaucrat intern("Intern", 100);
		Form form("Confidential Report", 10, 10);
		std::cout << form << std::endl;
		try
		{
			form.beSigned(intern);
			std::cout << "After beSigned(): " << form << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << "Form still signed? " << form.getIsSigned() << std::endl;
	}

	/* 8. Bureaucrat::signForm() - success case, prints confirmation */
	separator("Bureaucrat::signForm() success");
	{
		Bureaucrat director("Director", 1);
		Form contract("Employment Contract", 5, 5);
		std::cout << "Before: " << contract << std::endl;
		director.signForm(contract);
		std::cout << "After: " << contract << std::endl;
	}

	/* 9. Bureaucrat::signForm() - failure case, prints the reason */
	separator("Bureaucrat::signForm() failure");
	{
		Bureaucrat janitor("Janitor", 150);
		Form nda("Non-Disclosure Agreement", 2, 2);
		std::cout << "Before: " << nda << std::endl;
		janitor.signForm(nda);
		std::cout << "After: " << nda << std::endl;
	}

	/* 10. Bureaucrat::signForm() - signing an already-signed form still succeeds */
	separator("Bureaucrat::signForm() on an already-signed form");
	{
		Bureaucrat boss("Boss", 1);
		Form memo("Internal Memo", 10, 10);
		boss.signForm(memo);
		std::cout << "First sign result: " << memo << std::endl;
		boss.signForm(memo); // sign again, should just stay signed
		std::cout << "Second sign result: " << memo << std::endl;
	}

	/* 11. Form copy constructor and assignment operator */
	separator("Form copy constructor + assignment operator");
	try
	{
		Bureaucrat signer("Signer", 1);
		Form original("Original Form", 30, 30);
		original.beSigned(signer);

		Form copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;

		Form unsigned_("Unsigned Form", 40, 40);
		std::cout << "Before assignment: " << unsigned_ << std::endl;
		unsigned_ = original; // only the signed status is copied
		std::cout << "After assignment (unsigned_ = original): " << unsigned_ << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}