#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }

#include "stack.hpp"
#include <iterator>
#include <vector>
#include "vector.hpp"

template <typename T>
void printv(T x, T y) {
	std::cout << "print vector: {";
	while (x != y) {
		std::cout << *x << " ";
		++x;
	}
	std::cout << "}\n";
}

int main()
{
	ft::vector<int> vi;
	ft::vector<int>::iterator it;
	std::cout << vi.size() << ", " << vi.capacity() << std::endl;
	vi.push_back(7);
	std::cout << vi.size() << ", " << vi.capacity() << std::endl;
	vi.push_back(8);
	std::cout << vi.size() << ", " << vi.capacity() << std::endl;
	vi.push_back(9);
	std::cout << vi.size() << ", " << vi.capacity() << std::endl;
	it = vi.begin();
	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
	--it;
	ft::vector<int>::iterator it2;
	it2 = it;
	std::cout << *it2 << std::endl;
	std::cout << it2[2] << std::endl;
	std::cout << "============================\n";
	ft::vector<int> vii;
	vii = vi;
	vii.push_back(10);
	std::cout << vi.size() << " " << vii.size() << std::endl;
	ft::vector<int>::const_iterator it3;
	ft::vector<int>::const_iterator it4;
	it3 = vii.begin();
	it4 = vii.end();
	std::cout << vii.size() << " ==> " << it4 - it3 << " <==\n";
	std::vector<char> s(5, 'a');
	ft::vector<char> s1(5, 'a');
	s.reserve(20);
	s1.reserve(20);
	s.assign(3, 'c');
	s1.assign(3, 'c');
	s.resize(12, '5');
	s1.resize(12, '5');
	std::cout << s.size() << " " << s.capacity() << " " << s[2] << std::endl;
	printv(s.begin(), s.end());
	std::cout << s1.size() << " " << s1.capacity() << " " << s1[2] << std::endl;
	printv(s1.begin(), s1.end());
	std::cout << "============================\n";
	std::vector<int> vec(3, 0);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(13);
	vec.push_back(10);
	vec.push_back(7);
	ft::vector<int> ftvec(3, 0);
	ftvec.push_back(1);
	ftvec.push_back(5);
	ftvec.push_back(13);
	ftvec.push_back(10);
	ftvec.push_back(7);
	std::cout << *(vec.begin()) << " - " << *(ftvec.begin()) << std::endl << *(vec.end() - 1) << " - " << *(ftvec.end() - 1) << std::endl;
	std::vector<int> vect(vec.begin(), vec.end());
	printv(vect.begin(), vect.end());
	ft::vector<int> ftvect(ftvec.begin(), ftvec.end());
	printv(ftvect.begin(), ftvect.end());
	std::cout << "============================\n";
	printv(vec.begin(), vec.end());
	std::cout << "cap: " << vec.capacity() << "; size: " << vec.size() << std::endl;
	vec.assign(it3, it4);
	printv(vec.begin(), vec.end());
	std::cout << "cap: " << vec.capacity() << "; size: " << vec.size() << std::endl;
	std::cout << "--------------\n";
	printv(ftvec.begin(), ftvec.end());
	std::cout << "cap: " << ftvec.capacity() << "; size: " << ftvec.size() << std::endl;
	ftvec.assign(it3, it4);
	printv(ftvec.begin(), ftvec.end());
	std::cout << "cap: " << ftvec.capacity() << "; size: " << ftvec.size() << std::endl;
	std::cout << "============================\n";
	std::vector<int> vec1(1, 123);
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	vec1.insert(vec1.begin(), 11);
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	vec1.insert(vec1.begin(), 11);
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
}