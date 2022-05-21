#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>

template <typename T, typename Allocator = std::allocator<T> >
class redBlackTreeNode {
	typedef T					value_type;
	typedef	Allocator			allocator_type;
	typedef redBlackTreeNode*	node_pointer;

	value_type			_value;
	node_pointer		_left;
	node_pointer		_right;
	node_pointer		_parent;
	bool				_red;

};

#endif