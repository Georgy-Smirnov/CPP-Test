#ifndef REDBLACKRTEE_HPP
#define REDBLACKRTEE_HPP

#include "utility.hpp"

namespace ft {

template <typename T>
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
	redBlackTreeNode(const redBlackTreeNode& other)
		: _value(other._value), _left(other._left), _right(other._right), _parent(other._parent), _red(other._red) {}
	redBlackTreeNode& operator=(const redBlackTreeNode& other) {
		if (&other == this) return *this;
		_value = other._value;
		_left = other._left;
		_right = other._right;
		_parent = other._parent;
		_red = other._red;
		return *this;
	}
	~redBlackTreeNode() {}

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

// template <typename T>
// struct baseNode {
// 	typedef redBlackTreeNode<T>*	node_pointer;
// 	node_pointer 	_root;
// 	node_pointer 	_last;
// 	baseNode() : _root(nullptr), _last(nullptr) {}
// };

template <typename Value, typename Compare, typename Allocator>
class redBlackTree {
public:
	typedef Value												value_type;
	typedef Compare												key_compare;
	typedef Allocator											allocator_type;
	typedef std::size_t											size_type;	

	typedef redBlackTreeNode<value_type>		node;
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
	node_pointer	_root;
	node_allocator	_allocator;
	value_compare	_compare;
	size_type		_size;
public:
	redBlackTree() : _root(nullptr), _size(0), _compare(key_compare()) {}
	~redBlackTree() {
		//destroy;
		//deallocate;
	}
	size_type size() const { return _size; }
	// value_type ret() const { return _first->val(); }

	bool equal_compare(value_type a, value_type b) {
		return (!_compare(a, b) && !_compare(b, a));
	}

	void insert(const value_type& val) {
		node_pointer new_node = _allocator.allocate(1);
		_allocator.construct(new_node, val);
		if (_root == nullptr) {
			_root = new_node;
			new_node->_red = false;
		}
		node_pointer tmp = _root;
		node_pointer prev;
		while (tmp) {
			if (!_compare(val, tmp->_value) && !_compare(tmp->_value, val)) return;
			prev = tmp;
			if (_compare(val, tmp->_value))
				tmp = tmp->_left;
			else if (_compare(tmp->_value, val))
				tmp = tmp->_right;
		}
		new_node->_parent = prev;
		if (_compare(val, prev->_value))
				prev->_left = new_node;
		else if (_compare(prev->_value, val))
				prev->_right = new_node;
		balancing(new_node);
	}

	void balancing(node_pointer& node) {
		if (_root == node) { //если корень
			node->_red = false;
			return;
		}
		while (node->_parent && node->_parent->_red) { //пока отец красный
			if (node->grandparent() && (node->grandparent())->_left == node->_parent) { //если отец левый сын
				if (node->uncle() && (node->uncle())->_red) { // если дядя красный
					(node->uncle())->_red = false;
					node->_parent->_red = false;
					(node->grandparent())->_red = true;
					node = node->grandparent();
				}
				else {	// если дядя черный
					if (node->_parent->_right == node) {// правый сын
						node = node->_parent;
						rotate_left(node);
					}
					node->_parent->_red = false;
					(node->grandparent())->_red = true;
					rotate_right(node->grandparent());
				}
			}
			else { //если отец правый сын
				if (node->uncle() && (node->uncle())->_red) { // если дядя красный
					(node->uncle())->_red = false;
					node->_parent->_red = false;
					(node->grandparent())->_red = true;
					node = node->grandparent();
				}
				else { // если дядя черный
					if (node->_parent->_left == node) {// левый сын
						node = node->_parent;
						rotate_right(node);
					}
					node->_parent->_red = false;
					(node->grandparent())->_red = true;
					rotate_left(node->grandparent());
				}
			}
		}
		_root->_red = false;
	}

	void rotate_left(node_pointer n) {
		node_pointer son = n->_right;
		son->_parent = n->_parent;
		n->_parent = son;
		if (son->_parent) {
			if (son->_parent->_left == n)
				son->_parent->_left = son;
			else
				son->_parent->_right = son;
		}
		else
			_root = son;
		n->_right = son->_left;
		if (son->_left)
			n->_right->_parent = n;
		n->_parent = son;
		son->_left = n;
		}

		void rotate_right(node_pointer n) {
		node_pointer son = n->_left;
		son->_parent = n->_parent;
		if (n->_parent) {
			if (n->_parent->_left == n)
				n->_parent->_left = son;
			else
				n->_parent->_right = son;
		}
		else
			_root = son;
		n->_left = son->_right;
		if (son->_right)
			n->_left->_parent = n;
		n->_parent = son;
		son->_right = n;
		}

	void print_tree_rec(const node_pointer &tmp) const {
		if (tmp == nullptr)
			return ;
		print_tree_rec(tmp->return_left());
		tmp->print_node();
		std::cout << "Address: " << tmp << std::endl << std::endl;
		print_tree_rec(tmp->return_right());
	}

	void print_tree() const {
		std::cout << "\n\n************** root ***************\n" << "root: " << this->_root << "\n***********************************\n";
		print_tree_rec(this->_root);
	}
};

}

#endif