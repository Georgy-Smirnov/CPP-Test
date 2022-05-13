#include "Zombie.hpp"

int main(void)
{
	Zombie stack("stack");
	stack.announce();

	Zombie *heap;
	heap = newZombie("heap");
	heap->announce();
	delete heap;
	randomChump("Bill");
	return (0);
}