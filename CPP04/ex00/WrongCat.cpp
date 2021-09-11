#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "WrongCat constructor\n"; }

WrongCat::~WrongCat() { std::cout << "WrongCat distructor\n"; }

WrongCat::WrongCat(const WrongCat &tmp) : WrongAnimal(tmp.type) { std::cout << "WrongCat copy constructor\n"; }

WrongCat &WrongCat::operator=(const WrongCat &tmp)
{
	if (this == &tmp)
		return (*this);
	type = tmp.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong cat sound\n";
}