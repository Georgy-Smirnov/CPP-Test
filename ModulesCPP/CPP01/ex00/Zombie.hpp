#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

#include <iostream>

class Zombie
{
public:
	void	announce(void);
	~Zombie();
	Zombie(std::string name);
	void	set_name(std::string name);
	std::string get_name(void);
private:
	std::string _name;
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif