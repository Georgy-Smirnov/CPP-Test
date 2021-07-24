#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapone) : _weapone(weapone)
{
	this->_name = name;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << \
	this->_weapone.getType() << std::endl;
}