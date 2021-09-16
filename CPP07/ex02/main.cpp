#include <iostream>
#include "Array.hpp"

int main(void)
{
	try
	{
		Array<std::string> str(3);
		Array<int> i(2);
		i[0] = 1;
		i[1] = 2;
		str[0] = "Hello";
		str[1] = "World!";
		std::cout << i[0] << std::endl;
		std::cout << i[1] << std::endl;
		std::cout << str[0] << std::endl;
		std::cout << str[1] << std::endl;
		std::cout << str[2] << std::endl;
		i[INDEX] = 10;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}