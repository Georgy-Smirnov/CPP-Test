#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap &tmp);
	ScavTrap(std::string name);
	ScavTrap& operator =(const ScavTrap& tmp);
	void attack(std::string const &target);
	void guardGate();
};

#endif