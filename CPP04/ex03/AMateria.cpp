#include "AMateria.hpp"

AMateria::AMateria() : type("NO") {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& tmp) : type(tmp.type) {}

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria& AMateria::operator=(const AMateria& tmp)
{
	if (this == &tmp)
		return (*this);
	type = tmp.type;
	return (*this);
}

const std::string& AMateria::getType() const
{
	return(type);
}