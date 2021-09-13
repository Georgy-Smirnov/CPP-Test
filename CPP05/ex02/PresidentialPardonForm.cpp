#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& tmp) : Form("PresidentialPardonForm", 25, 5), target(tmp.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& tmp)
{
	if (this == &tmp)
		return (*this);
	*this = tmp;
	return (*this);
}

void PresidentialPardonForm::action() const
{
	std::cout << target << " has been pardoned by Zafod Beeblebrox\n";
}