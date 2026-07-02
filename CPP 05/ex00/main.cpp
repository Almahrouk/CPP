#include "Bureaucrat.hpp"

static void separator(const std::string & title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	/* 1. Default construction + insertion operator */
	separator("Default constructor + operator<<");
	Bureaucrat defaultGuy;
	std::cout << defaultGuy << std::endl;

	/* 2. Valid construction (mid-range grade) */
	separator("Valid construction");
	try
	{
		Bureaucrat alice("Alice", 42);
		std::cout << alice << std::endl;
		std::cout << "getName(): " << alice.getName() << std::endl;
		std::cout << "getGrade(): " << alice.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 3. Construction at the exact boundaries (1 and 150) should succeed */
	separator("Boundary construction (grade 1 and grade 150)");
	try
	{
		Bureaucrat topGrade("TopBoss", 1);
		std::cout << topGrade << std::endl;
		Bureaucrat bottomGrade("Intern", 150);
		std::cout << bottomGrade << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 4. Construction with grade too high (< 1) throws GradeTooHighException */
	separator("Grade too high (0)");
	try
	{
		Bureaucrat tooHigh("Overqualified", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	/* 5. Construction with grade too low (> 150) throws GradeTooLowException */
	separator("Grade too low (151)");
	try
	{
		Bureaucrat tooLow("Underqualified", 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	/* 6. Negative grade also throws GradeTooHighException */
	separator("Negative grade (-5)");
	try
	{
		Bureaucrat negative("Impossible", -5);
		std::cout << negative << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	/* 7. incrementGrade() - normal case (grade decreases numerically) */
	separator("incrementGrade() normal case");
	try
	{
		Bureaucrat bob("Bob", 3);
		std::cout << "Before increment: " << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 8. incrementGrade() - already at grade 1, must throw */
	separator("incrementGrade() at max grade (1)");
	try
	{
		Bureaucrat champion("Champion", 1);
		std::cout << "Before increment: " << champion << std::endl;
		champion.incrementGrade(); // the Destructor called ?? -> go to the catch block
		std::cout << "After increment: " << champion << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl; 
	}

	/* 9. decrementGrade() - normal case */
	separator("decrementGrade() normal case");
	try
	{
		Bureaucrat charlie("Charlie", 148);
		std::cout << "Before decrement: " << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 10. decrementGrade() - already at grade 150, must throw */
	separator("decrementGrade() at min grade (150)");
	try
	{
		Bureaucrat loser("Loser", 150);
		std::cout << "Before decrement: " << loser << std::endl;
		loser.decrementGrade();
		std::cout << "After decrement: " << loser << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	/* 11. Copy constructor */
	separator("Copy constructor");
	try
	{
		Bureaucrat original("Diana", 50);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 12. Assignment operator (name stays the same, grade is copied) */
	separator("Assignment operator");
	try
	{
		Bureaucrat eve("Eve", 20);
		Bureaucrat frank("Frank", 100);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "  " << eve << std::endl;
		std::cout << "  " << frank << std::endl;
		frank = eve;
		std::cout << "After assignment (frank = eve):" << std::endl;
		std::cout << "  " << eve << std::endl;
		std::cout << "  " << frank << " (name unchanged, grade copied)" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 13. Repeated incrementGrade() calls until exception is thrown */
	separator("Repeated incrementGrade() until exception");
	try
	{
		Bureaucrat grace("Grace", 3);
		for (int i = 0; i < 5; i++)
		{
			std::cout << grace << std::endl;
			grace.incrementGrade();
		}
	}
	catch (std::exception & e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	/* 14. std::exception & catch works for both exception types */
	separator("Catching both exception types via std::exception &");
	try
	{
		Bureaucrat bad1("Bad1", -1);
		(void)bad1;
	}
	catch (std::exception & e)
	{
		std::cerr << "Caught via std::exception &: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bad2("Bad2", 200);
		(void)bad2;
	}
	catch (std::exception & e)
	{
		std::cerr << "Caught via std::exception &: " << e.what() << std::endl;
	}

	return 0;
}