#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) { return (*this); }

Form* Intern::createShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::createRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::createPresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::makeForm(std::string form, std::string target)
{
	std::string arrayForm[3];
	arrayForm[0] = "presidential pardon";
	arrayForm[1] = "robotomy request";
	arrayForm[2] = "shrubbery creation";
	Form* (Intern::*arrayCreateForm[3])(std::string target);
	arrayCreateForm[0] = & Intern::createPresidentialPardon;
	arrayCreateForm[1] = & Intern::createRobotomyRequest;
	arrayCreateForm[2] = & Intern::createShrubberyCreation;
	for (size_t i = 0; i < 3; i++)
	{
		if (form == arrayForm[i])
			return (*this.*arrayCreateForm[i])(target);
	}
	throw (FormNotCreated());
}

const char* Intern::FormNotCreated::what() const throw()
{
	return ("Form was not found");
}