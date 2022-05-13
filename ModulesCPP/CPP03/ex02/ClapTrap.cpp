#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Default ClapTrap created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << Name << " ClapTrap deleted" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &tmp) : Name(tmp.Name), Hitpoints(tmp.Hitpoints), EnergyPoints(tmp.EnergyPoints), AttackDamage(tmp.AttackDamage)
{
	std::cout << Name << " ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : Name(name), Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << Name << " ClapTrap created" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& tmp)
{
	if (this == &tmp)
		return (*this);
	Name = tmp.Name;
	Hitpoints = tmp.Hitpoints;
	EnergyPoints = tmp.EnergyPoints;
	AttackDamage = tmp.AttackDamage;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << Name << " attack " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDammage(unsigned int ammount)
{
	std::cout << "ClapTrap " << Name << " take dammage " << ammount << std::endl;
}

void ClapTrap::beRepaired(unsigned int ammount)
{
	std::cout << "ClapTrap " << Name << " be repaired " << ammount << std::endl;
}