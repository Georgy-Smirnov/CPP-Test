#include "Classes.hpp"

Base::~Base() {}

Base* generate(void)
{
	std::srand(std::time(nullptr));
	int s = (std::rand() % 3);
	if (s == 0)
		return (new A());
	if (s== 1)
		return (new B());
	return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p)
{
	try
	{
		A& tmp =  dynamic_cast<A&>(p);
		std::cout << "A\n";
		(void)tmp;
	}
	catch (const std::bad_cast& e) {}
	try
	{
		B& tmp =  dynamic_cast<B&>(p);
		std::cout << "B\n";
		(void)tmp;
	}
	catch (const std::bad_cast& e) {}
	try
	{
		C& tmp =  dynamic_cast<C&>(p);
		std::cout << "C\n";
		(void)tmp;
	}
	catch (const std::bad_cast& e) {}
}

int main(void)
{
	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete (ptr);
}