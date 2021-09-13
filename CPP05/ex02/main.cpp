#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << "Bureaucrat create\n";
		Bureaucrat jhon("Jhon", 112);
		std::cout << "Bureaucrat create\n";
		ShrubberyCreationForm doc("Home");
		std::cout << "Form create\n";
		RobotomyRequestForm as("val");
		std::cout << "Form create\n";
		std::cout << doc;
		doc.beSigned(jhon);
		std::cout << doc;
		doc.execute(jhon);
		as.beSigned(bob);
		as.execute(bob);
		PresidentialPardonForm zxc("zxc");
		std::cout << "Form create\n";
		zxc.beSigned(bob);
		zxc.execute(bob);		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}