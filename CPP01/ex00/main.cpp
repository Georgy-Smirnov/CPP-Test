#include "Zombie.hpp"

int main(void)
{
	Zombie stack("stack");

	randomChump("heap");
	stack.announce();
	return (0);
}