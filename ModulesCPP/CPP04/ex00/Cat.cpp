#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "Cat constructor\n"; }

Cat::~Cat() { std::cout << "Cat distructor\n"; }

Cat::Cat(const Cat &tmp) : Animal(tmp.type) { std::cout << "Cat copy constructor\n"; }

Cat &Cat::operator=(const Cat &tmp)
{
	if (this == &tmp)
		return (*this);
	type = tmp.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "cat sound\n";
}