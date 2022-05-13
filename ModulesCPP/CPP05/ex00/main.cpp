#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << "Bureaucrat create\n";
		Bureaucrat jhon("Jhon", 15);
		std::cout << "Bureaucrat create\n";
		bob.DownRang();
		std::cout << "Bureaucrat down rang\n";
		jhon.upRang();
		std::cout << "Bureaucrat up rang\n";
		std::cout << bob << jhon;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}