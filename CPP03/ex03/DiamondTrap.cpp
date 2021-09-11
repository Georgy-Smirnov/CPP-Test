#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(), Name("Default")
{
	std::cout << "Default DiamondTrap created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << Name << " DiamondTrap deleted" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : FragTrap(), ScavTrap(), Name(name)
{
	ClapTrap::Name = name + "_clap_name";
	std::cout << Name << " DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& tmp)
{
	Name = tmp.Name;
	AttackDamage = tmp.AttackDamage;
	Hitpoints = tmp.Hitpoints;
	EnergyPoints = tmp.EnergyPoints;
	ClapTrap::Name = tmp.ClapTrap::Name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& tmp)
{
	if (this == &tmp)
		return (*this);
	Name = tmp.Name;
	Hitpoints = tmp.Hitpoints;
	EnergyPoints = tmp.EnergyPoints;
	AttackDamage = tmp.AttackDamage;
	ClapTrap::Name = tmp.ClapTrap::Name;
	return (*this);
}