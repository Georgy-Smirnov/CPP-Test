#ifndef _FORM_HPP_
# define _FORM_HPP_

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	~Form();
	Form(std::string name, unsigned int a, unsigned int b);
	Form(const Form& tmp);
	Form& operator=(const Form& tmp);
	std::string getName() const;
	bool getCheck() const;
	unsigned int getGradeForSigned() const;
	unsigned int getGradeForExecute() const;
	void beSigned(const Bureaucrat& b);
	
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
	Form();
	const std::string name;
	bool check;
	const unsigned int GradeForSigned;
	const unsigned int GradeForExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& a);

#endif