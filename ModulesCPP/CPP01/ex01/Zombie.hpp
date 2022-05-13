#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

#include <iostream>

class Zombie
{
public:
	void	announce(void);
	~Zombie();
	Zombie();
	void	set_name(std::string name);
	std::string get_name(void);
private:
	std::string _name;
};

Zombie *ZombieHorde(int N, std::string name);

#endif