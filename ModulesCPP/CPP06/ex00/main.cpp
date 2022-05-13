#include "Conversion.hpp"

int main(int argc, char**argv)
{
	if (argc == 2)
	{
		try
		{
			Conversion a(argv[1]);
			a.printRezult();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}