#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "map.hpp"

// struct baseNode {
// 	baseNode *left;
// 	baseNode *right;
// 	baseNode() : left(nullptr),right(nullptr) {}
// 	baseNode(baseNode *a, baseNode *b) : left(a), right(b) {}
// 	baseNode(const baseNode& other) : left(other.left), right(other.right) {}
// 	baseNode& operator=(const baseNode& other) {
// 		if (this == &other) return *this;
// 		left = other.left;
// 		right = other.right;
// 		return *this;
// 	}
// };

// struct node : baseNode {
// 	int value;
// 	node(int i) : baseNode(), value(i) {}
// 	node (const node& other) : baseNode(other.left, other.right), value(other.value) {}
// 	node& operator=(const node& other) {
// 		if (this == &other) return *this;
// 		value = other.value;
// 		left = other.left;
// 		right = other.right;
// 		return *this;
// 	}
// };

template <typename T>
struct node {
	node	*left;
	node	*right;
	T		value;
	node(T i = 0) : left(nullptr), right(nullptr), value(i) {}
	node (const node& other) : left(other.left), right(other.right), value(other.value) {}
	node& operator=(const node& other) {
		if (this == &other) return *this;
		left = other.left;
		right = other.right;
		value = other.value;
		return *this;
	}
};

template <typename T, typename Allocator = std::allocator<T> >
struct list {
	typedef node<T> node;
	node *_list;
	std::allocator<node> _allocator;
	list() { _list = _allocator.allocate(1); _list->left = nullptr; _list->right = nullptr; }
	void add(int i) {
		node *new_node = _allocator.allocate(1);
		_allocator.construct(new_node, i);
		node *tmp = _list;
		while (tmp->right)
			tmp = tmp->right;
		tmp->right = new_node;
		new_node->left = tmp;
	}

	void print_list() const {
		node *tmp = _list->right;
		while (tmp) {
			std::cout << tmp->value << " ";
			tmp = tmp->right;
		}
	}

	~list() {
		node *tmp = _list;
		while (_list->right) {
			tmp = _list;
			_list = _list->right;
			_allocator.destroy(tmp);
			_allocator.deallocate(tmp, 1);
		}
	}
};

class A {
	int a;
public:
	A(int a) : a(a) {}
};

int main(void)
{
	list<int> l;
	l.add(7);
	l.add(8);
	l.add(17);
	l.add(7321);
	l.add(7213);
	l.add(71);
	l.add(7675);
	l.add(5767);
	l.print_list();
	// ft::map<int, std::string> m;
		// std::map<int, A> mapp;
		// mapp.insert(std::make_pair<int, A>(int(), 5));
	// mapp.insert(std::make_pair<int, std::string>(5, "hello"));
	// mapp.insert(std::make_pair<int, std::string>(1, "h"));
	// mapp.insert(std::make_pair<int, std::string>(7, "sdello"));
	// mapp.insert(std::make_pair<int, std::string>(2, "helasdaasdo"));
	// std::map<int, std::string>::iterator it = mapp.begin();
	// // ++it;
	// mapp.insert(it, std::make_pair<int, std::string>(4, "heaasdlo"));
	// std::cout << (*it).first << " " << (*it).second << std::endl;
}
