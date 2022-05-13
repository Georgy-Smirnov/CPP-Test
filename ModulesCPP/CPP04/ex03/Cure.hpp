#ifndef _CURE_HPP_
# define _CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(const Cure& tmp);
	Cure& operator=(const Cure& tmp);
	Cure* clone() const;
	void use(ICharacter& target);
};

#endif