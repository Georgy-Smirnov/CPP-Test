#include "Zombie.hpp"

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string Zombie::get_name(void)
{
	return (this->_name);
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " delete!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
