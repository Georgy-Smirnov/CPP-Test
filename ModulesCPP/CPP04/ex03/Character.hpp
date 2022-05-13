#ifndef _CHARACTER_HPP_
# define _CHARACTER_HPP_

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	~Character();
	Character(const Character& tmp);
	Character(const std::string& name);
	Character& operator=(const Character& tmp);
	const std::string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	std::string name;
	AMateria** array;
};

#endif