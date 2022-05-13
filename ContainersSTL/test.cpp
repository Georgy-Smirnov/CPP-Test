#include <iostream>
#include <vector>
#include <map>
#include <iterator>

namespace test {

struct input_iterator_tag {} ;
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template <typename T>
struct iterator_traits {

};

template <class T, class Allocator = std::allocator<T> >
class vector {
private:
	T*					_array;
	int					_size;
	int					_capacity;
	std::allocator<T>	_alloc;
public:

	class IteratorVector {
	private:
		T* _pointer;
	public:
		IteratorVector() : _pointer(nullptr) {}
		IteratorVector(T* array) : _pointer(array) {}
		T& operator*() { return *_pointer; }
	};

	vector() {
		std::cout << "Constructor\n";
	}

	IteratorVector begin() const {
		return _array;
	}

	void push_back(const T& value) {
		_array = new T(value);

	}

	~vector() { delete _array; }
};
}

int main(void)
{
	test::vector<int> a;
	std::vector<int> b;

	for (size_t i = 0; i < 10; ++i)
		b.push_back(5);
	std::vector<int>::iterator it2 = b.begin();
	std::cout << std::is_same<std::iterator<std::vector<int>, int>, std::vector<int>::iterator>::value << std::endl;
	std::cout << sizeof(a) << " " << sizeof(b) << std::endl << std::endl;
	std::cout << it2[3] << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << b.capacity() << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;
	
	test::vector<int>::IteratorVector it;
	a.push_back(5);
	it = a.begin();
	std::cout << *it << std::endl;
	if (std::is_same<int, double>::value)
		std::cout << "!!!!\n";
	std::cout << sizeof(std::iterator_traits<std::vector<int>::iterator>) << std::endl;
}