#include <iostream>
#include <vector>

int main(void) {
	std::allocator<int> all;
	std::vector<int> a(all);
	std::cout << a.size() << "  " << a.capacity() << std::endl;
}
