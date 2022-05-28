#include "stack.hpp"
#include <iterator>
#include <vector>
#include <map>
#include "map.hpp"
#include "vector.hpp"

template <typename T>
void print_map(T& map) {
	typedef typename T::iterator iter;
	std::cout << "Map:{";
	for (iter i = map.begin(); i != map.end(); ++i)
		std::cout << "(" << (*i).first << " " << (*i).second << ") ";
	std::cout << "}\n";
}

void f() {
	typedef std::string str;
	// std::map<int, str> m;
	// m.insert(std::make_pair<int, str>(1, "one"));
	// m.insert(std::make_pair<int, str>(2, "two"));
	// m.insert(std::make_pair<int, str>(3, "three"));
	ft::map<int, str> ftm;
	ftm.insert(ft::make_pair<int, str>(1, "one"));
	ftm.insert(ft::make_pair<int, str>(2, "two"));
	ftm.insert(ft::make_pair<int, str>(3, "three"));
	ft::map<int, str>::iterator i = ftm.begin();
	ft::map<int, str> ftmm(ftm);
	// m.insert(std::make_pair<int, str>(5, "five"));
	// m.insert(std::make_pair<int, str>(10, "ten"));
	// m.insert(std::make_pair<int, str>(15, "fifteen"));
	// m.insert(std::make_pair<int, str>(20, "twenty"));
	print_map(ftm);
	// print_map(ftmm);
}

void voidf(ft::vector<int>::const_iterator iter) {}

int main()
{
	f();
	// while(1);
}