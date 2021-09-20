#ifndef _MUTANTSTACK_HPP_
# define _MUTANTSTACK_HPP_

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }

	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& tmp) : std::stack<T>(tmp) {}
	MutantStack& operator=(const MutantStack& tmp) { std::stack<T>::operator=(tmp); return (*this); }
	~MutantStack() {}
};

#endif