#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _requiredSignGrade(1), _requiredExecuteGrade(1)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int requiredSignGrade, int requiredExecuteGrade) : _name(name), _requiredSignGrade(requiredSignGrade), _requiredExecuteGrade(requiredExecuteGrade)
{
    std::cout << "Form parameterized constructor called" << std::endl;
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

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &obj) : _name(obj._name), _isSigned(obj._isSigned), _requiredSignGrade(obj._requiredSignGrade), _requiredExecuteGrade(obj._requiredExecuteGrade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form & Form::operator=(const Form &obj)
{
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &obj)
    {
        // name, requiredSignGrade and requiredExecuteGrade are const, so we cannot assign them
        // this->requiredSignGrade = obj.requiredSignGrade;
        // this->requiredExecuteGrade = obj.requiredExecuteGrade;
        this->_isSigned = obj._isSigned;
    }
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getRequiredSignGrade() const
{
    return this->_requiredSignGrade;
}

int Form::getRequiredExecuteGrade() const
{
    return this->_requiredExecuteGrade;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

void Form::incrementGrade()
{
    if (this->_requiredSignGrade <= 1)
        throw GradeTooHighException();
    this->_requiredSignGrade--;
}

void Form::decrementGrade()
{
    if (this->_requiredSignGrade >= 150)
        throw GradeTooLowException();
    this->_requiredSignGrade++;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_requiredSignGrade)
        throw GradeTooLowException();
    this->_isSigned = true;
}

std::ostream & operator<<(std::ostream & os, const Form & Form)
{
	os << Form.getName() << ", Form grade " << Form.getRequiredSignGrade() << ", Execute grade " << Form.getRequiredExecuteGrade() << ".";
	return (os);
}