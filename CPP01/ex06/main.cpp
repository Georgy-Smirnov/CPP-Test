#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen a;

	if (argc != 2)
	{
		std::cout << "Wrong arguments!" << std::endl;
		return (1);
	}
	else
		a.complain(argv[1]);
	return (0);
}