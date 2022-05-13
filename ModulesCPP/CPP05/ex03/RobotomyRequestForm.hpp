#ifndef _ROBOTOMYREQUESTFORM_HPP_
# define _ROBOTOMYREQUESTFORM_HPP_

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	~RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& tmp);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& tmp);
	void action() const;
private:
	RobotomyRequestForm();
	std::string target;
};

#endif