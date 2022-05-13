#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap& tmp);
	DiamondTrap& operator=(const DiamondTrap& tmp);
	void attack(std::string const &target);
	void WhoAmI();
private:
	std::string Name;
};

#endif