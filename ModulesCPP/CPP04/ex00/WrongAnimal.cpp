#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("void") { std::cout << "WrongAnimal constructor\n"; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal distructor\n"; }

WrongAnimal::WrongAnimal(const WrongAnimal& tmp) : type(tmp.type) { std::cout << "WrongAnimal copy constructor\n"; }

WrongAnimal::WrongAnimal(const std::string& type) : type(type) { std::cout << "WrongAnimal string constructor\n"; };

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& tmp)
{
	if (this == &tmp)
		return (*this);
	type = tmp.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "void sound\n";
}