#include "Form.hpp"

Form::Form() : GradeForSigned(1), GradeForExecute(1) {}

Form::~Form() {}

Form::Form(std::string name, unsigned int a, unsigned int b) : name(name), check(0), GradeForSigned(a), GradeForExecute(b)
{
	if (GradeForSigned < 1 || GradeForExecute < 1)
		throw (GradeTooHighException());
	if (GradeForSigned > 150 || GradeForExecute > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form& tmp) : name(tmp.name), check(tmp.check), GradeForSigned(tmp.GradeForSigned), GradeForExecute(tmp.GradeForExecute) {}

Form& Form::operator=(const Form& tmp)
{
	if (this == &tmp)
		return (*this);
	check = tmp.check;
	return (*this);
}

std::string Form::getName() const
{
	return (name);
}

bool Form::getCheck() const
{
	return (check);
}

unsigned int Form::getGradeForSigned() const
{
	return (GradeForSigned);
}

unsigned int Form::getGradeForExecute() const
{
	return (GradeForExecute);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (GradeForSigned >= b.getRang())
	{
		b.signForm(*this, 1);
		check = 1;
	}
	else
	{
		b.signForm(*this, 0);
		throw (GradeTooLowException());
	}
}

void Form::execute(const Bureaucrat& executor) const
{
	if (GradeForExecute >= executor.getRang())
	{
		if (check == 0)
			throw (FormNotSignedException());
		executor.executeForm(*this, 1);
		action();
	}
	else
	{
		executor.executeForm(*this, 0);
		throw (GradeTooLowException());
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is big");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is small");
}

const char* Form::FormNotSignedException::what() const throw()
{
	return ("Start execute form, which not signed");
}

std::ostream& operator<<(std::ostream& out, const Form& a)
{
	out << a.getName() << "_" << a.getCheck() << "_" << a.getGradeForSigned() << "_" << a.getGradeForExecute() << std::endl;
	return (out);
}