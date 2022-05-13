#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& tmp) : AMateria(tmp.type) {}

Cure& Cure::operator=(const Cure& tmp)
{
	if (this == &tmp)
		return (*this);
	type = tmp.type;
	return (*this);
}

Cure* Cure::clone() const
{
	Cure *cure = new Cure();
	*cure = *this;
	return (cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}