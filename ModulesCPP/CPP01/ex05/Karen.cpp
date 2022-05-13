#include "Karen.hpp"

void	Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	std::string debug_str = "DEBUG";
	std::string info_str = "INFO";
	std::string warning_str = "WARNING";
	std::string error_str = "ERROR";
	void (Karen::*debug_ptr)() = NULL;
	void (Karen::*info_ptr)() = NULL;
	void (Karen::*warning_ptr)() = NULL;
	void (Karen::*error_ptr)() = NULL;
	debug_ptr = &Karen::debug;
	info_ptr = &Karen::info;
	warning_ptr = &Karen::warning;
	error_ptr = &Karen::error;
	std::string array_str[4] = {debug_str, info_str, warning_str, error_str};
	void (Karen::*array[4])() = {debug_ptr, info_ptr, warning_ptr, error_ptr};
	for (int i = 0; i < 4; i++)
	{
		if (array_str[i] == level)
			(*this.*array[i])();
	}
	

}
