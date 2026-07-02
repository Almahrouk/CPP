#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _isSigned;
        int _requiredSignGrade;
        int _requiredExecuteGrade;
    public:
        Form();
        Form(const std::string &name, int requiredSignGrade, int requiredExecuteGrade);
        ~Form();
        Form(const Form &obj);
        Form & operator=(const Form &obj);

        // Getters
        std::string getName() const;
        bool getIsSigned() const;
        int getRequiredSignGrade() const;
        int getRequiredExecuteGrade() const;

        // Member functions
        void beSigned(const Bureaucrat &bureaucrat);
        void incrementGrade();
        void decrementGrade();

        // Exception classes
        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw();
        };
        
};

std::ostream & operator<<(std::ostream & os, const Form & form);

#endif