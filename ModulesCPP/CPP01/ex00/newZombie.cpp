#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *rez;
	
	rez = new Zombie(name);
	return (rez);
}
