#include "Dog.hpp"

Dog::Dog() : Animal("Dog") { std::cout << "Dog constructor\n"; }

Dog::~Dog() { std::cout << "Dog distructor\n"; }

Dog::Dog(const Dog &tmp) : Animal(tmp.type) { std::cout << "Dog copy constructor\n"; }

Dog &Dog::operator=(const Dog &tmp)
{
	if (this == &tmp)
		return (*this);
	type = tmp.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "dog sound\n";
}