#ifndef _WRONGANIMAL_HPP_
# define _WRONGANIMAL_HPP_

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& tmp);
	WrongAnimal(const std::string& type);
	WrongAnimal& operator=(const WrongAnimal& tmp);
	std::string getType() const;
	void makeSound() const;
protected:
	std::string type;
};

#endif