#ifndef _SHRUBBERYCREATIONFORM_HPP_
# define _SHRUBBERYCREATIONFORM_HPP_

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
public:
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& tmp);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& tmp);
	void action() const;
private:
	ShrubberyCreationForm();
	std::string target;
};

#endif