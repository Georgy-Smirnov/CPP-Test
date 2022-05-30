#include "vector.hpp"
#include <vector>
#include "map.hpp"
#include <map>
#include "set.hpp"
#include <set>
#include <chrono>
#include <fstream>
#include <sys/stat.h>

void test_vector(std::ofstream &f, std::ofstream &s);
void test_map(std::ofstream &f, std::ofstream &s);

int main()
{
	std::ofstream ft_file;
	std::ofstream std_file;
	system("rm -rf ./logs");
	mkdir("./logs", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	mkdir("./logs/vector", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	mkdir("./logs/map", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	mkdir("./logs/set", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	mkdir("./logs/stack", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	test_vector(ft_file, std_file);
	std::cout << std::endl;
	test_map(ft_file, std_file);
	// if (system("diff ./logs/fft_at.log ./logs/std_at.log") == 0)
	// 	std::cout << "\033[32m[OK] \033[m";
	// else
	// 	std::cout << "\033[31m[KO] \033[m";
	// if(system("diff a b") == 0)
	// std::cout << std::flush;
}