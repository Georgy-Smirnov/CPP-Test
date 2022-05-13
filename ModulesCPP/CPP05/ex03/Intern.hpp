#ifndef _INTERN_HPP_
# define _INTERN_HPP_

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &tmp);
	Intern& operator=(const Intern& tmp);
	Form* createShrubberyCreation(std::string target);
	Form* createRobotomyRequest(std::string target);
	Form* createPresidentialPardon(std::string target);
	Form* makeForm(std::string form, std::string target);

	class FormNotCreated : public std::exception
	{
	public:
		const char* what() const throw();
	};
private:
};

#endif