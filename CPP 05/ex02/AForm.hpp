#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>
#include <fstream>

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool _isSigned;
        int _requiredSignGrade;
        int _requiredExecuteGrade;
        virtual void	executeAction() const = 0;
    public:
        AForm();
        AForm(const std::string &name, int requiredSignGrade, int requiredExecuteGrade);
        ~AForm();
        AForm(const AForm &obj);
        AForm & operator=(const AForm &obj);
        std::string getName() const;
        bool getIsSigned() const;
        int getRequiredSignGrade() const;
        int getRequiredExecuteGrade() const;
        void beSigned(const Bureaucrat &bureaucrat);
        void incrementGrade();
        void decrementGrade();
        void execute(const Bureaucrat &executor) const;
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
        class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
        
};

std::ostream & operator<<(std::ostream & os, const AForm & aform);

#endif