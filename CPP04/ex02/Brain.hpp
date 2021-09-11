#ifndef _BRAIN_HPP_
# define _BRAIN_HPP_

#include <iostream>

class Brain
{
public:
	std::string *ideas;
	Brain();
	~Brain();
	Brain(const Brain& tmp);
	Brain& operator=(const Brain& tmp);
};

#endif