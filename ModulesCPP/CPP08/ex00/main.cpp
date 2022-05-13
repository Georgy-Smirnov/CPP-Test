#include "easyfind.hpp"
#include <vector>
#include <list>

template <typename T>
void printConteiner(const T& conteiner)
{
	typename T::const_iterator i = conteiner.begin();
	while (i != conteiner.end())
	{
		std::cout << *i << " ";
		++i;
	}
	std::cout << std::endl;
}

int main(void)
{
	std::srand(std::time(nullptr));
	std::vector<int> myVector;
	for (int count = 0; count < 100; ++count)
	    myVector.push_back((std::rand() % 100));
	std::list<int> myList;
	for (int count = 0; count < 5; ++count)
	    myList.push_back((std::rand() % 100));
	printConteiner(myVector);
	printConteiner(myList);
	try
	{
		std::vector<int>::iterator a = easyfind(myVector, 2);
		std::cout << *a << std::endl;
		std::list<int>::iterator b = easyfind(myList, 8);
		std::cout << *b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}