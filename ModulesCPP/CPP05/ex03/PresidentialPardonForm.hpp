#ifndef _PRESIDENTIALPARDONFORM_HPP_
# define _PRESIDENTIALPARDONFORM_HPP_

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	~PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& tmp);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& tmp);
	void action() const;
private:
	PresidentialPardonForm();
	std::string target;
};

#endif