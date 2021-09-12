#ifndef _AMATERIA_HPP_
# define _AMATERIA_HPP_

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	~AMateria();
	AMateria(const AMateria& tmp);
	AMateria(std::string const & type);
	AMateria& operator=(const AMateria& tmp);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	// virtual void use(ICharacter& target);
};

#endif