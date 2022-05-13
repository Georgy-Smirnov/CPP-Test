#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &tmp);
	ClapTrap(std::string name);
	ClapTrap& operator =(const ClapTrap& tmp);
	void attack(std::string const &target);
	void takeDammage(unsigned int ammount);
	void beRepaired(unsigned int ammount);
	int getHitpoints();
	int getEnergyPoints();
	int getAttackDamage();
protected:
	std::string Name;
	int	Hitpoints;
	int EnergyPoints;
	int	AttackDamage;
};

#endif