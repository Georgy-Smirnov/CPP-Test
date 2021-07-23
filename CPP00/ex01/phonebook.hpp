#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include <iostream>
# include <iomanip>

class contact
{
public:
	void	put_in_first_name(std::string str);
	std::string	take_first_name(void);
	void	put_in_last_name(std::string str);
	std::string	take_last_name(void);
	void	put_in_nick_name(std::string str);
	std::string	take_nick_name(void);
	void	put_in_phone_number(std::string str);
	std::string	take_phone_number(void);
	void	put_in_darkest_secret(std::string str);
	std::string	take_darkest_secret(void);
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nick_name;
	std::string	_phone_number;
	std::string	_darkest_secret;
};

#endif