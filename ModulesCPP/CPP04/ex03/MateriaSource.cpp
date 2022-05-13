#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : mat1(nullptr), mat2(nullptr), mat3(nullptr), mat4(nullptr) {}

MateriaSource::~MateriaSource()
{
	if (mat1 != nullptr)
		delete (mat1);
	if (mat2 != nullptr)
		delete (mat2);
	if (mat3 != nullptr)
		delete (mat3);
	if (mat4 != nullptr)
		delete (mat4);
}

MateriaSource::MateriaSource(const MateriaSource& tmp)
{
	if (tmp.mat1 != nullptr)
		mat1 = tmp.mat1->clone();
	if (tmp.mat2 != nullptr)
		mat2 = tmp.mat2->clone();
	if (tmp.mat3 != nullptr)
		mat3 = tmp.mat3->clone();
	if (tmp.mat4 != nullptr)
		mat4 = tmp.mat4->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& tmp)
{
	if (this == &tmp)
		return (*this);
	if (mat1 != nullptr)
		delete (mat1);
	if (mat2 != nullptr)
		delete (mat2);
	if (mat3 != nullptr)
		delete (mat3);
	if (mat4 != nullptr)
		delete (mat4);
	if (tmp.mat1 != nullptr)
		mat1 = tmp.mat1->clone();
	if (tmp.mat2 != nullptr)
		mat2 = tmp.mat2->clone();
	if (tmp.mat3 != nullptr)
		mat3 = tmp.mat3->clone();
	if (tmp.mat4 != nullptr)
		mat4 = tmp.mat4->clone();
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (mat1 == nullptr)
		mat1 = materia;
	else if (mat2 == nullptr)
		mat2 = materia;
	else if (mat3 == nullptr)
		mat3 = materia;
	else if (mat4 == nullptr)
		mat4 = materia;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	if (mat1->getType() == type)
		return (mat1);
	if (mat2->getType() == type)
		return (mat2);
	if (mat3->getType() == type)
		return (mat3);
	if (mat4->getType() == type)
		return (mat4);
	return (nullptr);
}