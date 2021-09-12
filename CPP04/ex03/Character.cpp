#include "Character.hpp"

Character::Character() : name("Default"), array(new AMateria*[4])
{
	for (size_t i = 0; i < 4; i++)
		array[i] = nullptr;
}

Character::~Character()
{
	delete[] array;
}

Character::Character(const Character& tmp) : name(tmp.name), array(new AMateria*[4])
{
	for (size_t i = 0; i < 4; i++)
		array[i] = tmp.array[i];
}

Character::Character(const std::string& name) : name(name), array(new AMateria*[4])
{
	for (size_t i = 0; i < 4; i++)
		array[i] = nullptr;
}

Character& Character::operator=(const Character& tmp)
{
	if (this == &tmp)
		return (*this);
	delete[] (array);
	name = tmp.name;
	array = new AMateria*[4];
	for (size_t i = 0; i < 4; i++)
		array[i] = tmp.array[i];
	return (*this);

}

const std::string& Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	size_t i = 0;
	while (array[i] != nullptr && i < 4)
		i++;
	if (i != 4)
		array[i] = m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		array[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	array[idx]->use(target);
}