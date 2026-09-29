#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form defaultForm;
	std::cout << defaultForm << std::endl;
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
	return 0;
}