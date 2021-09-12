#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& tmp) : AMateria(tmp.type) {}

Ice& Ice::operator=(const Ice& tmp)
{
	if (this == &tmp)
		return (*this);
	type = tmp.type;
	return (*this);
}

Ice* Ice::clone() const
{
	Ice *ice = new Ice();
	*ice = *this;
	return (ice);
}