#include "span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(unsigned int n) : size(n)
{
	vec.reserve(size);
}

Span::Span(const Span& tmp) : vec(tmp.vec) {}

Span& Span::operator=(const Span& tmp)
{
	if (this == &tmp)
		return (*this);
	vec = tmp.vec;
	return (*this);
}

void Span::addNumber(int num)
{
	if (vec.size() < size)
		vec.push_back(num);
	else
		throw (OutOfIndex());
}

unsigned int diff(int a, int b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}

unsigned int Span::shortestSpan() const
{
	if (vec.size() < 2)
		throw (FewArgumentsInConteiner());
	unsigned int rezult = diff(vec[0], vec[1]);
	std::vector<int> tmp(vec);
	sort(tmp.begin(), tmp.end());
	for (unsigned int i = 0; i < size - 1; ++i)
	{
		if (rezult > diff(tmp[i], tmp[i + 1]))
			rezult = diff(tmp[i], tmp[i + 1]);
	}
	return (rezult);
}

unsigned int Span::longestSpan() const
{
	if (vec.size() < 2)
		throw (FewArgumentsInConteiner());
	return (*(std::max_element(vec.begin(), vec.end())) - *(std::min_element(vec.begin(), vec.end())));
}

void Span::printSpan() const
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

const char* Span::FewArgumentsInConteiner::what() const throw()
{
	return ("Few arguments");
}

const char* Span::OutOfIndex::what() const throw()
{
	return ("Out of index");
}