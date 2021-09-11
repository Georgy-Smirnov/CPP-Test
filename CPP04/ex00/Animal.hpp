#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

#include <iostream>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& tmp);
	Animal(const std::string& type);
	Animal& operator=(const Animal& tmp);
	std::string getType() const;
	virtual void makeSound() const;
protected:
	std::string type;
};

#endif