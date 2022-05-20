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
	{
	std::vector<int> vec1(3, 123);
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	vec1.insert(vec1.begin(), 11);
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	vec1.insert(vec1.begin() + 1, 111);
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	std::cout << "--------------\n";
	ft::vector<int> ftvec1(3, 123);
	printv(ftvec1.begin(), ftvec1.end());
	std::cout << "cap: " << ftvec1.capacity() << "; size: " << ftvec1.size() << std::endl;
	ftvec1.insert(ftvec1.begin(), 11);
	printv(ftvec1.begin(), ftvec1.end());
	std::cout << "cap: " << ftvec1.capacity() << "; size: " << ftvec1.size() << std::endl;
	ftvec1.insert(ftvec1.begin() + 1, 111);
	printv(ftvec1.begin(), ftvec1.end());
	std::cout << "cap: " << ftvec1.capacity() << "; size: " << ftvec1.size() << std::endl;
	}
	std::cout << "============================\n";
	{
	std::vector<int> vec1(10, 123);
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	vec1.insert(vec1.begin() + 1, 5, 99);
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	std::vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	vec1.insert(vec1.begin() + 5, tmp.begin(), tmp.end());
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	std::cout << "--------------\n";
	ft::vector<int> ftvec1(10, 123);
	printv(ftvec1.begin(), ftvec1.end());
	std::cout << "cap: " << ftvec1.capacity() << "; size: " << ftvec1.size() << std::endl;
	ftvec1.insert(ftvec1.begin() + 1, 5, 99);
	printv(ftvec1.begin(), ftvec1.end());
	std::cout << "cap: " << ftvec1.capacity() << "; size: " << ftvec1.size() << std::endl;
	ft::vector<int> tmp1;
	tmp1.push_back(1);
	tmp1.push_back(2);
	tmp1.push_back(3);
	ftvec1.insert(ftvec1.begin() + 5, tmp1.begin(), tmp1.end());
	printv(ftvec1.begin(), ftvec1.end());
	std::cout << "cap: " << ftvec1.capacity() << "; size: " << ftvec1.size() << std::endl;
	std::cout << "============================\n";
	std::cout << "rez: " << *(vec1.erase(vec1.begin() + 5)) << std::endl;
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	std::cout << "rez: " << *(vec1.erase(vec1.begin() + 3, vec1.end() - 2)) << std::endl;
	printv(vec1.begin(), vec1.end());
	std::cout << "cap: " << vec1.capacity() << "; size: " << vec1.size() << std::endl;
	std::cout << "--------------\n";
	std::cout << "rez: " << *(ftvec1.erase(ftvec1.begin() + 5)) << std::endl;
	printv(ftvec1.begin(), ftvec1.end());
	std::cout << "cap: " << ftvec1.capacity() << "; size: " << ftvec1.size() << std::endl;
	std::cout << "rez: " << *(ftvec1.erase(ftvec1.begin() + 3, ftvec1.end() - 2)) << std::endl;
	printv(ftvec1.begin(), ftvec1.end());
	std::cout << "cap: " << ftvec1.capacity() << "; size: " << ftvec1.size() << std::endl;

	}
}