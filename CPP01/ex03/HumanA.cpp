#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapone)
{
	this->_name = name;
	this->_weapone = &weapone;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << \
	this->_weapone->getType() << std::endl;
}