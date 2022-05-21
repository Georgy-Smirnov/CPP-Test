#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "map.hpp"

int main(void)
{
	typedef ft::pair<int, std::string> pair;
	pair q(5, "hello");
	ft::redBlackTreeNode<pair, std::allocator<pair> > n(q);
	std::cout << n.val().first << " " << n.val().second << std::endl;
}
