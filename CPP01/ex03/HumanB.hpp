#ifndef _HUMANB_HPP_
# define _HUMANB_HPP_

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
	void	attack(void);
	HumanB (std::string name);
	void	setWeapon(Weapon &club);
private:
	std::string _name;
	Weapon		*_weapone;
};

#endif