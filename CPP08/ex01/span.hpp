#ifndef _SPAN_HPP_
# define _SPAN_HPP_

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span& tmp);
	Span& operator=(const Span& tmp);
	~Span();
	void addNumber(int num);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	void printSpan() const;

	class OutOfIndex : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class FewArgumentsInConteiner : public std::exception
	{
	public:
		const char* what() const throw();
	};
private:
	std::vector<int> vec;
	unsigned int size;
	Span();
};

#endif