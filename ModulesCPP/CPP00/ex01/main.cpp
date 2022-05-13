#include "ClassPhonebook.hpp"

void	display_number(Phonebook &book, int i)
{
	std::cout << std::setw(17) << "First name:" << book.contacs[i - 1].take_first_name() << std::endl;
	std::cout << std::setw(17) << "Last name:" << book.contacs[i - 1].take_last_name() << std::endl;
	std::cout << std::setw(17) << "Nickname:" << book.contacs[i - 1].take_nick_name() << std::endl;
	std::cout << std::setw(17) << "Phone number:" << book.contacs[i - 1].take_phone_number() << std::endl;
	std::cout << std::setw(17) << "Darkest secret:" << book.contacs[i - 1].take_darkest_secret() << std::endl;
}

void	add_in_phonebook(Phonebook &book, int &i)
{
	std::string	str;
	int	tmp = i % 8;

	std::cout << "Enter first name:" << std::endl;
	getline(std::cin, str);
	if (!std::cin)
		exit (0);
	book.contacs[tmp].put_in_first_name(str);
	std::cout << "Enter last name:" << std::endl;
	getline(std::cin, str);
	if (!std::cin)
		exit (0);
	book.contacs[tmp].put_in_last_name(str);
	std::cout << "Enter nick name:" << std::endl;
	getline(std::cin, str);
	if (!std::cin)
		exit (0);
	book.contacs[tmp].put_in_nick_name(str);
	std::cout << "Enter phone number:" << std::endl;
	getline(std::cin, str);
	if (!std::cin)
		exit (0);
	book.contacs[tmp].put_in_phone_number(str);
	std::cout << "Enter darkset secret:" << std::endl;
	getline(std::cin, str);
	if (!std::cin)
		exit (0);
	book.contacs[tmp].put_in_darkest_secret(str);
	i++;
	std::cout << "OK" << std::endl;
}

std::string pop_str(std::string str)
{
	while (str.length() > 10)
	{
		str.pop_back();
		str.pop_back();
		str.push_back('.');
	}
	return (str);
}

void	display_phonebook(Phonebook &book, int count)
{
	int i = 0;
	std::string number;
	std::cout << "*********************************************" << std::endl;
	while (i < count && i < 8)
	{
		std::cout << "=============================================" << std::endl;
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << pop_str(book.contacs[i].take_first_name()) << "|";
		std::cout << std::setw(10) << pop_str(book.contacs[i].take_last_name()) << "|";
		std::cout << std::setw(10) << pop_str(book.contacs[i].take_nick_name()) << "|" << std::endl;
		i++;
	}
	std::cout << "=============================================" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << "Enter number: " << std::endl;
	getline(std::cin, number);
	if (!std::cin)
		exit (0);
	if (number[0] > '0' && number[0] < '9' && number[1] == '\0' && std::stoi(number) <= count)
		display_number(book, std::stoi(number));
	else
		std::cout << "Wrong number!" << std::endl;
}

void	start_work_programm(Phonebook &book, int &count)
{
	std::string str;

	getline(std::cin, str);
	if (!std::cin)
		exit (0);
	if (str == "ADD")
		add_in_phonebook(book, count);
	else if (str == "SEARCH")
		display_phonebook(book, count);
	else if (str == "EXIT")
		exit (0);
	else
		std::cout << "Incorrect command!" << std::endl;
}

int	main(void)
{
	Phonebook	book;
	int			count = 0;

	std::cout << "Start programm:" << std::endl;
	while (1)
		start_work_programm(book, count);
}