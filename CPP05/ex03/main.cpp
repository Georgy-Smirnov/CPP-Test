#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf;
		delete (rrf);
		rrf = someRandomIntern.makeForm("presidential pardon", "bob");
		std::cout << *rrf;
		delete (rrf);
		rrf = someRandomIntern.makeForm("hello", "Poll");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}