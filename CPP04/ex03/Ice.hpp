#ifndef _ICE_HPP_
# define _ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice& tmp);
	Ice& operator=(const Ice& tmp);
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif