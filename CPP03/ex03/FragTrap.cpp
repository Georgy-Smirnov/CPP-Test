#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	Hitpoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "Default FragTrap created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << Name << " FragTrap deleted" << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	Hitpoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << Name << " FragTrap created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& tmp)
{
	Name = tmp.Name;
	Hitpoints = tmp.Hitpoints;
	EnergyPoints = tmp.EnergyPoints;
	AttackDamage = tmp.AttackDamage;
	std::cout << Name << " FragTrap created" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& tmp)
{
	if (this == &tmp)
		return (*this);
	Name = tmp.Name;
	Hitpoints = tmp.Hitpoints;
	EnergyPoints = tmp.EnergyPoints;
	AttackDamage = tmp.AttackDamage;
	return (*this);
}

void FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap " << Name << " attack " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << Name << " a positive high fives request" << std::endl;
}