#include "Animal.hpp"

Animal::Animal() : type("void") { std::cout << "Animal constructor\n"; }

Animal::~Animal() { std::cout << "Animal distructor\n"; }

Animal::Animal(const Animal& tmp) : type(tmp.type) { std::cout << "Animal copy constructor\n"; }

Animal::Animal(const std::string& type) : type(type) { std::cout << "Animal string constructor\n"; };

Animal& Animal::operator=(const Animal& tmp)
{
	if (this == &tmp)
		return (*this);
	type = tmp.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}