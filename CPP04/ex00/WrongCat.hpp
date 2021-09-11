#ifndef _WRONGCAT_HPP_
# define _WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& tmp);
	WrongCat& operator=(const WrongCat& tmp);
	void makeSound() const;
};

#endif