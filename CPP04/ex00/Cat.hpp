#ifndef _CAT_HPP_
# define _CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat& tmp);
	Cat& operator=(const Cat& tmp);
	void makeSound() const;
};

#endif