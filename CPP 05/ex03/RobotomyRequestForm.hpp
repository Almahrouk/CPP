#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        const std::string	_target;
        virtual void	executeAction() const;

	public:
		// Orthodox Canonical Form
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string & target);
		RobotomyRequestForm(const RobotomyRequestForm & other);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
		~RobotomyRequestForm();
};

#endif