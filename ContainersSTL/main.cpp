#include "stack.hpp"
#include <iterator>
#include <vector>
#include <map>
#include "map.hpp"
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

template <class T, class V>
std::vector<int> erase_test_3(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 500 * 10000; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    mp.erase(mp.begin(), --mp.end());
    v.push_back(mp.begin()->first);
    return v;
}

template <class T, class V>
std::vector<int> erase_test_3(ft::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 500 * 10000; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
    mp.erase(mp.begin(), --mp.end());
    v.push_back(mp.begin()->first);
    return v;
}

void f() {
	// std::map<int, int> smp;
	// std::vector<int> v = erase_test_3(smp);
	// printv<std::vector<int>::iterator>(v.begin(), v.end());

	ft::map<int, int> mp;
	std::vector<int> v1 = erase_test_3(mp);
	printv<std::vector<int>::iterator>(v1.begin(), v1.end());
}

int main()
{
	f();
	// while(1);
}