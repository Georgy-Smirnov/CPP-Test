#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& tmp) : Form("RobotomyRequestForm", 72, 45), target(tmp.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& tmp)
{
	if (this == &tmp)
		return (*this);
	*this = tmp;
	return (*this);
}

void RobotomyRequestForm::action() const
{
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << target << " has been robotomized!\n";
	else
		std::cout << target << " has not been robotomized\n";
}