#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
}