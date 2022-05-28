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
	std::map<int, str> m;
	m.insert(std::make_pair<int, str>(1, "one"));
	m.insert(std::make_pair<int, str>(2, "two"));
	m.insert(std::make_pair<int, str>(3, "three"));
	m.insert(std::make_pair<int, str>(5, "five"));
	ft::map<int, str> ftm;
	ftm.insert(ft::make_pair<int, str>(1, "one"));
	ftm.insert(ft::make_pair<int, str>(2, "two"));
	ftm.insert(ft::make_pair<int, str>(3, "three"));
	ftm.insert(ft::make_pair<int, str>(5, "five"));
	print_map(m);
	print_map(ftm);
	std::map<int, str>::iterator i = m.upper_bound(1);
	ft::map<int, str>::iterator fti = ftm.upper_bound(1);
	std::cout << (*i).second << std::endl;
	std::cout << (*fti).second << std::endl;
}

void voidf(ft::vector<int>::const_iterator iter) {}

int main()
{
	f();
	// while(1);
}