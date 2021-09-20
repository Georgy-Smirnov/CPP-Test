#ifndef _EASYFIND_HPP_
# define _EASYFIND_HPP_

#include <iostream>

class NotFound : public std::exception
{
public:
	const char* what() const throw()
	{
		return ("Not found");
	}
};

template <typename T>
typename T::iterator easyfind(T& conteiner, int a)
{
	typename T::iterator i = std::find(conteiner.begin(), conteiner.end(), a);
	if (i == conteiner.end())
		throw (NotFound());
	return (i);	
}

#endif