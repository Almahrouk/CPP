#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("Default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        // _target is const, so we cannot assign it
    }
    return *this;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (!outFile)
    {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    outFile << "       _-_" << std::endl;
    outFile << "    /~~   ~~\\" << std::endl;
    outFile << " /~~         ~~\\" << std::endl;
    outFile << "{    ~~         }" << std::endl;
    outFile << " \\  _-     -_  /" << std::endl;
    outFile << "   ~  \\   //  ~" << std::endl;
    outFile << "_- -   |   | _- _" << std::endl;
    outFile << "  _ -  |   |   -_" << std::endl;
    outFile << "      //   \\\\" << std::endl;

    outFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

