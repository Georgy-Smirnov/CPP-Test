#include <iostream>
#include <vector>
#include "vector.hpp"

template <typename T>
void f(typename ft::enable_if<ft::is_integral<T>::value, T>::type a, T b) {
	std::cout <<"first\n";
}

// template <typename T>
// void f(T a, T b) {
// 	std::cout << "second\n";
// }

// template <>
// void f<int>(int a, int b) {
// 	std::cout << "third\n";
// }

int main(void) {
	f<int>('0', '1');
}
