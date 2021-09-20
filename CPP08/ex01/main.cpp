#include "span.hpp"

#define COUNT 10000

int main(void)
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::srand(std::time(nullptr));

		Span a(COUNT);
		for (unsigned int i = 0; i < COUNT; i++)
			a.addNumber(std::rand());
		a.printSpan();
		std::cout << "shortesSpan: " << a.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << a.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}