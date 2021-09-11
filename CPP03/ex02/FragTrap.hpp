#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap(std::string const name);
	FragTrap(const FragTrap& tmp);
	FragTrap& operator =(const FragTrap& tmp);
	void attack(std::string const &target);
	void highFivesGuys(void);
};

#endif