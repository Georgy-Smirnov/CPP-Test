#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	Hitpoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "Default ScavTrap created" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << Name << " ScavTrap deleted" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& tmp)
{
	Name = tmp.Name;
	Hitpoints = tmp.Hitpoints;
	EnergyPoints = tmp.EnergyPoints;
	AttackDamage = tmp.AttackDamage;
	std::cout << Name << " ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	Hitpoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << Name << " ScavTrap created" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& tmp)
{
	if (this == &tmp)
		return (*this);
	Name = tmp.Name;
	Hitpoints = tmp.Hitpoints;
	EnergyPoints = tmp.EnergyPoints;
	AttackDamage = tmp.AttackDamage;
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << Name << " attack " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << Name << " have enterred in Gate keeper mode" << std::endl;
}