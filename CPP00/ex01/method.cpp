#include "phonebook.hpp"

void	contact::put_in_first_name(std::string str)
{
	this->_first_name = str;
}

std::string	contact::take_first_name(void)
{
	return (this->_first_name);
}

void	contact::put_in_last_name(std::string str)
{
	this->_last_name = str;
}

std::string	contact::take_last_name(void)
{
	return (this->_last_name);
}

void	contact::put_in_nick_name(std::string str)
{
	this->_nick_name = str;
}

std::string	contact::take_nick_name(void)
{
	return (this->_nick_name);
}

void	contact::put_in_phone_number(std::string str)
{
	this->_phone_number = str;
}

std::string	contact::take_phone_number(void)
{
	return (this->_phone_number);
}

void	contact::put_in_darkest_secret(std::string str)
{
	this->_darkest_secret = str;
}

std::string	contact::take_darkest_secret(void)
{
	return (this->_darkest_secret);
}