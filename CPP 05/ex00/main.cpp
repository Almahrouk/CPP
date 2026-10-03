#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat defaultGuy;
	std::cout << defaultGuy << std::endl;

	try
	{
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
		std::cout << "getName(): " << alice.getName() << std::endl;
		std::cout << "getGrade(): " << alice.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}