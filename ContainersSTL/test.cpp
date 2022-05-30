#include "vector.hpp"
#include <vector>
#include "map.hpp"
#include <map>
#include "set.hpp"
#include <set>
#include <chrono>
#include <fstream>
#include <sys/stat.h>

#define C 10 //vector
#define M 10 //map

/******************************************************************************/
/*************************** vector test **************************************/
/******************************************************************************/

size_t std_construct_1(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi;
	std::vector<std::string> vs;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vs.size() << " " << vs.capacity();
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_construct_1(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi;
	ft::vector<std::string> vs;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vs.size() << " " << vs.capacity();
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_construct_2(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C);
	std::vector<std::string> vs(C, "hello");
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << vs.size() << " " << vs.capacity() << vs[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_construct_2(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C);
	ft::vector<std::string> vs(C, "hello");
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << vs.size() << " " << vs.capacity() << vs[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_construct_3(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vs(vi.begin(), vi.end() - 1);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << vs.size() << " " << vs.capacity() << vs[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_construct_3(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vs(vi.begin(), vi.end() - 1);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << vs.size() << " " << vs.capacity() << vs[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_construct_4(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vs(vi);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << vs.size() << " " << vs.capacity() << vs[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_construct_4(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vs(vi);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << vs.size() << " " << vs.capacity() << vs[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_operator_1(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vs(C / 2, 12);
	vs = vi;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << vs.size() << " " << vs.capacity() << vs[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_operator_1(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vs(C / 2, 12);
	vs = vi;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << vs.size() << " " << vs.capacity() << vs[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_assign_1(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	vi.assign(C / 2, 5);
	vi.assign(C * 2, 7);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_assign_1(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	vi.assign(C / 2, 5);
	vi.assign(C * 2, 7);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_assign_2(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vs(C / 2, 12);
	vi.assign(vs.begin(), vs.end() - 5);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[5] << " " << vs.size() << " " << vs.capacity() << " " << vs[3];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_assign_2(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vs(C / 2, 12);
	vi.assign(vs.begin(), vs.end() - 5);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[5] << " " << vs.size() << " " << vs.capacity() << " " << vs[3];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_at(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii(C, 20);
	int i = vi.at(C / 2);
	const int j = vii.at(C / 2);
	try { i = vi.at(C * 2); }
	catch (...) {}
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << i << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_at(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii(C, 20);
	int i = vi.at(C / 2);
	const int j = vii.at(C / 2);
	try { i = vi.at(C * 2); }
	catch (...) {}
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << vi[C - 1] << " " << i << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_operator_sq(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii(C, 20);
	int i = vi[C / 2];
	const int j = vii[C / 2];
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_operator_sq(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii(C, 20);
	int i = vi[C / 2];
	const int j = vii[C / 2];
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_front(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii(C, 20);
	int i = vi.front();
	const int j = vii.front();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_front(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii(C, 20);
	int i = vi.front();
	const int j = vii.front();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_back(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii(C, 20);
	int i = vi.back();
	const int j = vii.back();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_back(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii(C, 20);
	int i = vi.back();
	const int j = vii.back();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_data(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii(C, 20);
	int* i = vi.data();
	const int* j = vii.data();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_data(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii(C, 20);
	int* i = vi.data();
	const int* j = vii.data();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_begin(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii(C, 20);
	std::vector<int>::iterator i = vi.begin();
	std::vector<int>::const_iterator j = vii.begin();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_begin(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii(C, 20);
	ft::vector<int>::iterator i = vi.begin();
	ft::vector<int>::const_iterator j = vii.begin();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_end(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii(C, 20);
	std::vector<int>::iterator i = vi.end() - 1;
	std::vector<int>::const_iterator j = vii.end() - 1;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_end(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii(C, 20);
	ft::vector<int>::iterator i = vi.end() - 1;
	ft::vector<int>::const_iterator j = vii.end() - 1;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_rbegin(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii(C, 20);
	std::vector<int>::reverse_iterator i = vi.rbegin();
	std::vector<int>::const_reverse_iterator j = vii.rbegin();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_rbegin(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii(C, 20);
	ft::vector<int>::reverse_iterator i = vi.rbegin();
	ft::vector<int>::const_reverse_iterator j = vii.rbegin();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_rend(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii(C, 20);
	std::vector<int>::reverse_iterator i = vi.rbegin();
	std::vector<int>::const_reverse_iterator j = vii.rbegin();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_rend(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii(C, 20);
	ft::vector<int>::reverse_iterator i = vi.rend() - 1;
	ft::vector<int>::const_reverse_iterator j = vii.rend() - 1;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << *i << *j << vii[0] << vi[1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_empty(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii;
	bool i = vi.empty();
	bool j = vii.empty();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_empty(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii;
	bool i = vi.empty();
	bool j = vii.empty();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_size(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	const std::vector<int> vii;
	size_t i = vi.size();
	size_t j = vii.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_size(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	const ft::vector<int> vii;
	size_t i = vi.size();
	size_t j = vii.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_reserve(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	size_t i = vi.capacity();
	vi.reserve(C + 5);
	size_t j = vi.capacity();
	vi.reserve(C - 5);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_reserve(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	size_t i = vi.capacity();
	vi.reserve(C + 5);
	size_t j = vi.capacity();
	vi.reserve(C - 5);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_insert(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.insert(vi.begin() + 5, 12);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[5];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_insert(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.insert(vi.begin() + 5, 12);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[5];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_insert_2(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.insert(vi.begin() + 5, 12, 7);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[5];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_insert_2(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.insert(vi.begin() + 5, 12, 7);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[5];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_insert_3(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vii(C, 10);
	size_t i = vi.size();
	vi.insert(vi.begin(), vii.begin(), vii.begin() + 5);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[3];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_insert_3(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vii(C, 10);
	size_t i = vi.size();
	vi.insert(vi.begin(), vii.begin(), vii.begin() + 5);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[3];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_erase(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.erase(vi.begin() + 5);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[3];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_erase(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.erase(vi.begin() + 5);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[3];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_erase_1(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.erase(vi.begin(), vi.begin() + 5);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[3];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_erase_1(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.erase(vi.begin(), vi.begin() + 5);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[3];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_push_back(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.push_back(5);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_push_back(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.push_back(5);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_pop_back(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.pop_back();
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_pop_back(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.pop_back();
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_resize(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.resize(10, 2);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_resize(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	size_t i = vi.size();
	vi.resize(10, 2);
	size_t j = vi.size();
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << j << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_swap(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vii(C, 10);
	size_t i = vi.size();
	vi.swap(vii);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_swap(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vii(C, 10);
	size_t i = vi.size();
	vi.swap(vii);
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << vi[C - 1];
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_equal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vii(C, 10);
	bool i = vi == vii;
	vii.resize(C, 20);
	bool j = vi == vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_equal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vii(C, 10);
	bool i = vi == vii;
	vii.resize(C, 20);
	bool j = vi == vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_nequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vii(C, 10);
	bool i = vi != vii;
	vii.resize(C, 20);
	bool j = vi != vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_nequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vii(C, 10);
	bool i = vi != vii;
	vii.resize(C, 20);
	bool j = vi != vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_sequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vii(C, 10);
	bool i = vi < vii;
	vii.resize(C, 20);
	bool j = vi < vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_sequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vii(C, 10);
	bool i = vi < vii;
	vii.resize(C, 20);
	bool j = vi < vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_bequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vii(C, 10);
	bool i = vi > vii;
	vii.resize(C, 20);
	bool j = vi > vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_bequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vii(C, 10);
	bool i = vi > vii;
	vii.resize(C, 20);
	bool j = vi > vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_snequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vii(C, 10);
	bool i = vi <= vii;
	vii.resize(C, 20);
	bool j = vi <= vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_snequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vii(C, 10);
	bool i = vi <= vii;
	vii.resize(C, 20);
	bool j = vi <= vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t std_bnequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::vector<int> vi(C, 20);
	std::vector<int> vii(C, 10);
	bool i = vi >= vii;
	vii.resize(C, 20);
	bool j = vi >= vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

size_t ft_bnequal(std::ofstream& f) {
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	ft::vector<int> vi(C, 20);
	ft::vector<int> vii(C, 10);
	bool i = vi >= vii;
	vii.resize(C, 20);
	bool j = vi >= vii;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	f << vi.size() << " " << vi.capacity() << " " << " " << i << vii[1] << " " << vi[C - 1] << j;
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

void test_vector(std::ofstream& f, std::ofstream& s) {
	std::string ffirst = "./logs/vector/ft_";
	std::string sfirst = "./logs/vector/std_";
	std::string name;
	std::string command;


	std::cout << "\033[33m********************************************************************\n" << "*                               vector                             *\n" << "********************************************************************\n";
	std::cout << "\033[m\033[34mMember:\t\t\tTime std\t\tTime ft\t\tdiff\033[m\n";

	name = "construct_1.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Construct()\t\t" << std_construct_1(f) << "\t\t\t" << ft_construct_1(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "construct_2.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Construct(count, val)\t" << std_construct_2(f) << "\t\t\t" << ft_construct_2(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "construct_3.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Construct(iterator)\t" << std_construct_3(f) << "\t\t\t" << ft_construct_3(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "construct_copy.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Construct(copy)\t\t" << std_construct_4(f) << "\t\t\t" << ft_construct_4(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "operator=.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Operator=\t\t" << std_operator_1(f) << "\t\t\t" << ft_operator_1(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "assign_1.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Assign(count, value)\t" << std_assign_1(f) << "\t\t\t" << ft_assign_1(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "assign_2.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Assign(iterator)\t" << std_assign_2(f) << "\t\t\t" << ft_assign_2(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "at.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "At\t\t\t" << std_at(f) << "\t\t\t" << ft_at(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "operator[].log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Operator[]\t\t" << std_operator_sq(f) << "\t\t\t" << ft_operator_sq(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "front.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Front\t\t\t" << std_front(f) << "\t\t\t" << ft_front(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "back.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Back\t\t\t" << std_back(f) << "\t\t\t" << ft_back(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "data.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Data\t\t\t" << std_data(f) << "\t\t\t" << ft_data(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "begin.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Begin\t\t\t" << std_begin(f) << "\t\t\t" << ft_begin(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "end.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "End\t\t\t" << std_end(f) << "\t\t\t" << ft_end(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "rbegin.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Rbegin\t\t\t" << std_rbegin(f) << "\t\t\t" << ft_rbegin(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "rend.log";
		f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Rend\t\t\t" << std_rend(f) << "\t\t\t" << ft_rend(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;
	
	name = "empty.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Empty\t\t\t" << std_empty(f) << "\t\t\t" << ft_empty(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "size.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Size\t\t\t" << std_size(f) << "\t\t\t" << ft_size(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "reserve.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Reserve\t\t\t" << std_reserve(f) << "\t\t\t" << ft_reserve(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "insert_1.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Insert(pos)\t\t" << std_insert(f) << "\t\t\t" << ft_insert(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "insert_2.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Insert(pos, count)\t" << std_insert_2(f) << "\t\t\t" << ft_insert_2(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "insert_3.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Insert(iterator)\t" << std_insert_3(f) << "\t\t\t" << ft_insert_3(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "erase.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Erase(pos)\t\t" << std_erase(f) << "\t\t\t" << ft_erase(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "erase_1.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Erase(iterator)\t\t" << std_erase_1(f) << "\t\t\t" << ft_erase_1(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "push_back.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Push back\t\t" << std_push_back(f) << "\t\t\t" << ft_push_back(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "pop_back.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Pop back\t\t" << std_pop_back(f) << "\t\t\t" << ft_pop_back(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "resize.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Resize\t\t\t" << std_resize(f) << "\t\t\t" << ft_resize(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "swap.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Swap\t\t\t" << std_swap(f) << "\t\t\t" << ft_swap(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "operator==.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Operator==\t\t" << std_equal(f) << "\t\t\t" << ft_equal(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "operator!=.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Operator!=\t\t" << std_nequal(f) << "\t\t\t" << ft_nequal(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

		name = "operator_less.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Operator<\t\t" << std_sequal(f) << "\t\t\t" << ft_sequal(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "operator_big.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Operator>\t\t" << std_bequal(f) << "\t\t\t" << ft_bequal(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "operator_less_equal.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Operator<=\t\t" << std_snequal(f) << "\t\t\t" << ft_snequal(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;

	name = "operator_big_equal.log";
	f.open(ffirst + name);
	s.open(sfirst + name);
	std::cout << "Operator>=\t\t" << std_bnequal(f) << "\t\t\t" << ft_bnequal(s) << "\t\t";
	f.close();
	s.close();
	command = ((const_cast<char*>("diff ")) + ffirst + name + (const_cast<char*>(" ")) + sfirst + name);
	std::cout << ((system(&command[0]) == 0) ? "\033[32m[OK] \033[m" : "\033[31m[KO] \033[m") << std::endl;
	std::cout << "\033[33m********************************************************************\033[m\n";
}

/******************************************************************************/
/***************************** map test ***************************************/
/******************************************************************************/

void test_map(std::ofstream& f, std::ofstream& s) {
	std::string ffirst = "./logs/map/ft_";
	std::string sfirst = "./logs/map/std_";
	std::string name;
	std::string command;


	std::cout << "\033[33m********************************************************************\n" << "*                                map                               *\n" << "********************************************************************\n";
	std::cout << "\033[m\033[34mMember:\t\t\tTime std\t\tTime ft\t\tdiff\033[m\n";


}