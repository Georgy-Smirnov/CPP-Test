#ifndef _HUMANA_HPP_
# define _HUMANA_HPP_

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
public:
	void	attack(void);
	HumanA (std::string name, Weapon &weapone);
private:
	std::string _name;
	Weapon		&_weapone;
};

#endif