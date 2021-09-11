#include "Brain.hpp"

Brain::Brain() : ideas(new std::string[100])
{
	std::cout << "Brain construtor\n";
}

Brain::~Brain()
{
	delete[] (ideas);
	std::cout << "Brain distructor\n";
}

Brain::Brain(const Brain& tmp) : ideas(new std::string[100])
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = tmp.ideas[i];
	std::cout << "Brain copy construtor\n";
}

Brain& Brain::operator=(const Brain& tmp)
{
	delete[] (ideas);
	ideas = new std::string[100];
	for (size_t i = 0; i < 100; i++)
		ideas[i] = tmp.ideas[i];
	std::cout << "Brain operator =\n";
	return (*this);
}