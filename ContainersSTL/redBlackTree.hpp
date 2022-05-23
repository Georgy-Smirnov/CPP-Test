#ifndef REDBLACKRTEE_HPP
#define REDBLACKRTEE_HPP

#include "utility.hpp"

namespace ft {

template <typename T, typename Allocator>
struct redBlackTreeNode {
	typedef T																value_type;
	typedef redBlackTreeNode*												node_pointer;

	value_type		_value;
	node_pointer 	_left;
	node_pointer 	_right;
	node_pointer 	_parent;
	bool			_red;

	explicit redBlackTreeNode(const value_type &val = value_type())
		: _value(val), _left(nullptr), _right(nullptr), _parent(nullptr), _red(true) {}
	const value_type& val() const { return _value; }//TEST
	
	bool color() { return _red; }

	void change_color() {
		if (_red == false)
			_red = true;
		else
			_red = false;
	}

 	node_pointer grandparent() {
		if (_parent != nullptr && _parent->_parent != nullptr)
			return _parent->_parent;
		else
			return nullptr;
	}

	node_pointer uncle() {
		node_pointer gp = this->grandparent();
		if (gp == nullptr) return nullptr;
		if (gp->_left == this->_parent)
			return gp->_right;
		return gp->_left;	
	}

	void print_node() {
		std::cout << "==> This Node is ";
		if (_red == true)
			std::cout << "RED <==\n";
		else
			std::cout << "BLACK <==\n";
		std::cout << "==>first: " << _value.first << " second: " << _value.second << " <==\n";
		std::cout << "==>left: " << _left << " right: " << _right << " parent: " << _parent << " <==";
	}

	node_pointer return_left() { return _left; }
	node_pointer return_right() { return _right; }
};

template <typename T, typename Allocator>
struct baseNode {
	typedef redBlackTreeNode<T, Allocator>*	node_pointer;
	node_pointer 	_root;
	node_pointer 	_last;
	baseNode() : _root(nullptr), _last(nullptr) {}
};

template <typename Value, typename Compare, typename Allocator>
class redBlackTree {
public:
	typedef Value												value_type;
	typedef Compare												key_compare;
	typedef Allocator											allocator_type;
	typedef std::size_t											size_type;	
	typedef redBlackTreeNode<value_type, allocator_type>		node;
	typedef baseNode<value_type, allocator_type>				base_node;
	typedef typename Allocator::template rebind<node>::other	node_allocator;
	typedef	typename node_allocator::pointer					node_pointer;
	class value_compare : public std::binary_function<value_type, value_type, bool>
	{
	protected:
	    key_compare comp;
	public:
	    value_compare(const key_compare& pred) : comp(pred) {}
	    bool operator()(const value_type& left, const value_type& right) const {
			return comp(left.first, right.first);
		}
	};
private:
	base_node		*_root;
	node_pointer	_first;
	node_allocator	_allocator;
	value_compare	_compare;
	size_type		_size;
public:
	redBlackTree() : _root(new base_node()), _first(nullptr), _size(0), _compare(key_compare()) {}

	size_type size() const { return _size; }
	value_type ret() const { return _first->val(); }

	bool equal_compare(value_type a, value_type b) {
		return (!_compare(a, b) && !_compare(b, a));
	}

	void insert(const value_type& val) {
		node_pointer now = simple_insert(_root->_root, val);
		if (now == nullptr) return;// Maybe throw
		++_size;
		// insert_case1(now);
	}

	node_pointer& simple_insert(node_pointer &node, const value_type& val) {
		if (node == nullptr) {
			node = _allocator.allocate(1);
			_allocator.construct(node, val);//try
			return node;
		}
		else if (_compare(val, node->_value)) {
			node_pointer& tmp = simple_insert(node->_left, val);
			node->_left->_parent = node;
			return tmp;
		}
		else if (_compare(node->_value, val)) {
			node_pointer& tmp = simple_insert(node->_right, val);
			node->_right->_parent = node;
			return tmp;
		}
		return node;
	}

	// void insert_case1(node_pointer &n) {
	// 	if (n->_parent == nullptr)
	// 		n->_red = false;
	// 	else insert_case2(n);
	// }

	// void insert_case2(node_pointer &n) {
	// 	if (n->_parent->_red == false)
	// 		return;
	// 	else insert_case3(n);
	// }

	// void insert_case3(node_pointer &n) {
	// 	node_pointer u = n->uncle();
	// 	node_pointer g = n->grandparent();
	// 	if (u && u->_red) {
	// 		n->_parent->_red = false; 
	// 		u->_red = false;
	// 		g->_red = true;
	// 		insert_case1(g);
	// 	}
	// 	else insert_case4(n);
	// }

	// void insert_case4(node_pointer &n) {
	// 	std::cout << "grand: " << n->_parent->_parent << std::endl;
	// 	std::cout << "n    : " << n->_parent << std::endl;
	// 	std::cout << "right: " << n << std::endl << std::endl;
	// 	node_pointer g = n->grandparent();
	// 	if (n == n->_parent->_right && n->_parent == g->_left) {
	// 		rotate_left(n->_parent);
	// 		std::cout << "n    : " << n->_parent << std::endl;
	// 		std::cout << "leftt: " << n << std::endl;
	// 		std::cout << "grand: " << n->_parent->_left << std::endl << std::endl;
	// 		n = n->_left;
	// 		std::cout << "grand: " << n->_parent->_parent << std::endl;
	// 		std::cout << "n    : " << n->_parent << std::endl;
	// 		std::cout << "leftt: " << n << std::endl << std::endl;
	// 	}
		// else if (n == n->_parent->_left && n->_parent == g->_right) {
		// 	rotate_right(n->_parent);
		// 	n = n->_right;
		// }
		// insert_case5(n);
	// }

	// void insert_case5(node_pointer &n) {
		// std::cout << "addres2: " << n << std::endl;
		// std::cout << "addres2.2: " << n->_parent << std::endl;
		// std::cout << "addres2.2: " << n->_parent->_parent << std::endl;
		// std::cout << "addres2.3: " << n->_parent->_left << std::endl << std::endl;
		// node_pointer g = n->grandparent();
		// std::cout << "addres2.4: " << n->_parent << std::endl;
		// std::cout << "addres2.5: " << g->_left << std::endl;
		// n->_parent->_red = false;
		// g->_red = true;
		// if ((n == n->_parent->_left) && (n->_parent == g->_left))
		// 	rotate_right(g);
		// else { std::cout << "HEY!\n"; }
			// rotate_left(g);
	// }

	// void rotate_left(node_pointer &n) {
	// 	node_pointer pivot = n->_right;	
	// 	pivot->_parent = n->_parent;
	// 	if (n->_parent != NULL) {
	// 	    if (n->_parent->_left==n)
	// 	        n->_parent->_left = pivot;
	// 	    else
	// 	        n->_parent->_right = pivot;
	// 	}		

	// 	n->_right = pivot->_left;
	// 	if (pivot->_left != NULL)
	// 	    pivot->_left->_parent = n;

	// 	n->_parent = pivot;
	// 	pivot->_left = n;
	// }

	// void rotate_right(node_pointer &n) {
	// 	node_pointer pivot = n->_left;	
	// 	pivot->_parent = n->_parent;
	// 	if (n->_parent != NULL) {
	// 	    if (n->_parent->_left==n)
	// 	        n->_parent->_left = pivot;
	// 	    else
	// 	        n->_parent->_right = pivot;
	// 	}		
	// 	n->_left = pivot->_right;
	// 	if (pivot->_right != NULL)
	// 	    pivot->_right->_parent = n;

	// 	n->_parent = pivot;
	// 	pivot->_right = n;
	// }

	void print_tree_rec(const node_pointer &tmp) const {
		if (tmp == nullptr)
			return ;
		print_tree_rec(tmp->return_left());
		tmp->print_node();
		std::cout << "Address: " << tmp << std::endl << std::endl;
		print_tree_rec(tmp->return_right());
	}

	void print_tree() const {
		std::cout << "************** root ***************\n" << "root: " << this->_root->_root << "\nlast: " << this->_root->_last << "\n***********************************\n";
		print_tree_rec(this->_root->_root);
	}
};

}

#endif