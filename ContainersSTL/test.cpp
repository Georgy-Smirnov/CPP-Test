#include "vector.hpp"
#include <vector>
#include "map.hpp"
#include <map>

template <typename T, typename Allocator = std::allocator<T> >
class testVector {
	std::vector<T, Allocator> vec;
	ft::vector<T, Allocator> ftvec;
public:
	testVector() : vec(), ftvec() {}
	testVector(T one, T two) : vec(one), ftvec(two) {}
	void print_rez() const;
};

template <typename T, typename Allocator>
void testVector<T, Allocator>::print_rez() const {
	typedef typename std::vector<T, Allocator>::iterator iter;
	typedef typename ft::vector<T, Allocator>::iterator ftiter;
	std::cout << "================= std vector ======================\n";
	for (iter i = vec.begin(); i != vec.end(); ++i) {
		std::cout << *i << " ";
	}
	// std::cout << "================== ft vector ======================\n";
	// for (ftiter i = ftvec.begin(); i != ftvec.end(); ++i) {
	// 	std::cout << *i << " ";
	// }
	// std::cout << "==============================================\n";
}

void test_vector() {
	{
	testVector<int> test(5, 5);
	test.print_rez();
	}
}

int main(void) {
	test_vector();
}