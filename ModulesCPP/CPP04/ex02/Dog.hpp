#ifndef _DOG_HPP_
# define _DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog& tmp);
	Dog& operator=(const Dog& tmp);
	void makeSound() const;
private:
	Brain *brain;
};

#endif