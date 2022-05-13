#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat constructor\n";
}

Cat::~Cat()
{
	delete (brain);
	std::cout << "Cat distructor\n";
}

Cat::Cat(const Cat &tmp) : Animal(tmp.type), brain(new Brain())
{
	*brain = *(tmp.brain);
	std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator=(const Cat &tmp)
{
	if (this == &tmp)
		return (*this);
	delete (brain);
	brain = new Brain();
	type = tmp.type;
	*brain = *(tmp.brain);
	std::cout << "Cat operator =\n";
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "cat sound\n";
}