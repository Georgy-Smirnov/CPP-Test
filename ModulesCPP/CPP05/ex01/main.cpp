#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << "Bureaucrat create\n";
		Bureaucrat jhon("Jhon", 100);
		std::cout << "Bureaucrat create\n";
		Form doc("Document", 1, 2);
		std::cout << "Form create\n";
		std::cout << doc;
		doc.beSigned(bob);
		std::cout << doc;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}