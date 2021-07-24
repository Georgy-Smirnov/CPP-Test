#include "Zombie.hpp"
#define COUNT 5

int main(void)
{
	Zombie *horde;
	int i = 0;

	horde = ZombieHorde(COUNT, "Member_horde");
	while (i < COUNT)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
}