#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &club)
{
	this->_weapone = &club;
}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapone = NULL;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his " << \
	this->_weapone->getType() << std::endl;
}