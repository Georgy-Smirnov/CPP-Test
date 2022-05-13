#include <iostream>

struct Data
{
	std::string str;
	int integer1;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data *ptr = new Data;
	ptr->integer1 = 123;
	ptr->str = "Hello World!";
	uintptr_t variable;
	variable = serialize(ptr);
	Data *d;
	d = deserialize(variable);
	std::cout << d->integer1 << std::endl << d->str << std::endl;
	delete (d);
}