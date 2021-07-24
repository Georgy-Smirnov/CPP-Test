#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie *heap;
	
	heap = newZombie(name);
	heap->announce();
	delete heap;
}