#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int rang) : name(name), rang(rang)
{
	if (rang < 1)
		throw (GradeTooHighException());
	if (rang > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& tmp) : name(tmp.name), rang(tmp.rang) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& tmp)
{
	if (this == &tmp)
		return (*this);
	rang = tmp.rang;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

unsigned int Bureaucrat::getRang() const
{
	return (rang);
}

void Bureaucrat::upRang()
{
	--rang;
	if (rang < 1)
	{
		++rang;
		throw (GradeTooHighException());
	}
}

void Bureaucrat::DownRang()
{
	++rang;
	if (rang > 150)
	{
		--rang;
		throw (GradeTooLowException());
	}
}

void Bureaucrat::signForm(const Form& f, bool success) const
{
	if (success)
		std::cout << name << " signed " << f.getName() << std::endl;
	else
		std::cout << name << " cannot sign " << f.getName() << " because rang Bueraucrat - "<< rang << " Grade for signed - " << f.getGradeForSigned() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("rang > 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("rang < 150");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& b)
{
	out << b.getName() << "_" << b.getRang() << std::endl;
	return (out);
}