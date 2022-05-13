#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_

#include <iostream>

class Weapon
{
public:
	Weapon (std::string type);
	void	setType(std::string type);
	const	std::string& getType(void);
private:
	std::string	_type;
};

#endif