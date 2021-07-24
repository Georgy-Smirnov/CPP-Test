#include <iostream>
#include <fstream>

void	replace(char **argv, std::string tmp)
{
	std::ofstream		ofile;
	std::string			name;
	std::string			rez;
	int					checker;

	name = argv[1];
	name += ".replace";
	rez = "\0";
	ofile.open(name);
	if (!ofile.is_open())
	{
		std::cout << "Can't open file" << std::endl;
		exit (1);
	}
	while (1)
	{
		checker = tmp.find(argv[2]);
		if (checker == -1)
		{
			rez += tmp;
			break ;
		}
		rez += tmp.substr(0, checker);
		rez += argv[3];
		tmp = tmp.substr(checker + strlen(argv[2]));
	}
	ofile << rez;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong arguments!" << std::endl;
		return (1);
	}
	else
	{
		std::ifstream		ifile;
		std::string	tmp;

		ifile.open(argv[1]);
		if (!ifile.is_open())
		{
			std::cout << "Can't open file" << std::endl;
			return (1);
		}
		std::getline(ifile, tmp, '\0');
		ifile.close();
		replace(argv, tmp);
	}
}