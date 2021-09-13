#ifndef _BUREAUCRAT_HPP
# define _BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& tmp);
	Bureaucrat(const std::string& name, unsigned int rang);
	Bureaucrat& operator=(const Bureaucrat& tmp);
	std::string getName() const;
	unsigned int getRang() const;
	void upRang();
	void DownRang();
	void signForm(const Form& f, bool success) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
private:
	Bureaucrat();
	const std::string name;
	unsigned int rang;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& b);

#endif