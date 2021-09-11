#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog constructor\n";
}

Dog::~Dog()
{
	delete (brain);
	std::cout << "Dog distructor\n";
}

Dog::Dog(const Dog &tmp) : Animal(tmp.type), brain(new Brain())
{
	*brain = *(tmp.brain);
	std::cout << "Dog copy constructor\n";
}

Dog &Dog::operator=(const Dog &tmp)
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

void Dog::makeSound() const
{
	std::cout << "dog sound\n";
}