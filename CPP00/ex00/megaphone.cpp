#include <iostream>
using namespace std;

char *change(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int main(int argc, char **argv)
{
	int i = 1;
	
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
	while (i < argc)
	{
		cout << change(argv[i]);
		i++;
	}
	cout << endl;
	return (0);
}
