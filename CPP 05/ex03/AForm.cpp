#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _requiredSignGrade(1), _requiredExecuteGrade(1)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int requiredSignGrade, int requiredExecuteGrade) : _name(name), _requiredSignGrade(requiredSignGrade), _requiredExecuteGrade(requiredExecuteGrade)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
    try
    {
        if (requiredSignGrade < 1 || requiredExecuteGrade < 1)
            throw GradeTooHighException();
        else if (requiredSignGrade > 150 || requiredExecuteGrade > 150)
            throw GradeTooLowException();
        this->_isSigned = false;
    }
    catch (std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        throw; // rethrow the exception to indicate failure
    }
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &obj) : _name(obj._name), _isSigned(obj._isSigned), _requiredSignGrade(obj._requiredSignGrade), _requiredExecuteGrade(obj._requiredExecuteGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm & AForm::operator=(const AForm &obj)
{
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &obj)
    {
        // name is const, so we cannot assign it
        // this->_requiredSignGrade = obj._requiredSignGrade;
        // this->_requiredExecuteGrade = obj._requiredExecuteGrade;
        this->_isSigned = obj._isSigned;
    }
    return *this;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getRequiredSignGrade() const
{
    return this->_requiredSignGrade;
}

int AForm::getRequiredExecuteGrade() const
{
    return this->_requiredExecuteGrade;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low";
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

void AForm::incrementGrade()
{
    if (this->_requiredSignGrade <= 1)
        throw GradeTooHighException();
    this->_requiredSignGrade--;
}

void AForm::decrementGrade()
{
    if (this->_requiredSignGrade >= 150)
        throw GradeTooLowException();
    this->_requiredSignGrade++;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_requiredSignGrade)
        throw GradeTooLowException();
    this->_isSigned = true;
}

void AForm::execute(const Bureaucrat & executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_requiredExecuteGrade)
		throw AForm::GradeTooLowException();
	this->executeAction();
}

std::ostream & operator<<(std::ostream & os, const AForm & form)
{
	os << "Form <" << form.getName() << ">, "
	   << "signed: " << (form.getIsSigned() ? "yes" : "no") << ", "
	   << "grade required to sign: " << form.getRequiredSignGrade() << ", "
	   << "grade required to execute: " << form.getRequiredExecuteGrade();
	return (os);
}