#ifndef REDBLACKRTEE_HPP
#define REDBLACKRTEE_HPP

#include "iterators.hpp"

namespace ft {

template <typename T>
struct redBlackTreeNode {
	typedef T					value_type;
	typedef redBlackTreeNode*	node_pointer;
	value_type		_value;
	node_pointer 	_left;
	node_pointer 	_right;
	node_pointer 	_parent;
	bool			_red;

	explicit redBlackTreeNode(node_pointer& nil, const value_type &val = value_type())
		: _value(val), _left(nil), _right(nil), _parent(nullptr), _red(true) {}

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
		// std::cout << "==>first: " << _value.first << " second: " << _value.second << " <==\n";
		std::cout << "==>VALUE: " << _value << " <==\n";
		std::cout << "==>left: " << _left << " right: " << _right << " parent: " << _parent << " <==";
	}

	node_pointer return_left() { return _left; }
	node_pointer return_right() { return _right; }
};

template <typename U>
class IteratorTree;

template <typename Value, typename Compare = std::less<Value>, typename Allocator = std::allocator<Value> >
class redBlackTree {
public:
	typedef std::size_t												size_type;
	typedef Value													value_type;
	typedef Compare													value_compare;
	typedef Allocator												allocator_type;
	typedef redBlackTreeNode<value_type>							node;
	typedef typename allocator_type::template rebind<node>::other	node_allocator;
	typedef	typename node_allocator::pointer						node_pointer;
	typedef IteratorTree<value_type>								iterator;
private:
	node_pointer	_root;
	node_pointer	_nil;
	node_allocator	_allocator;	
	value_compare	_compare;
	size_type		_size;
public:
	explicit redBlackTree(value_compare comp = value_compare())
		: _root(nullptr), _nil(nullptr), _allocator(node_allocator()), _compare(comp), _size(0) {
		_nil = _allocator.allocate(1);
		_nil->_parent = nullptr;
		_nil->_right = nullptr;
		_nil->_left = nullptr;
		_nil->_red = false;
	}
	~redBlackTree() {
		//destroy;
		//deallocate;
	}
	size_type size() const { return _size; }

	bool equal_compare(value_type a, value_type b) {
		return (!_compare(a, b) && !_compare(b, a));
	}

	void insert(const value_type& val) {
		node_pointer new_node = _allocator.allocate(1);
		_allocator.construct(new_node, _nil, val);
		if (_nil->_left == nullptr)
			_nil->_left = new_node;
		else if (_compare(val, _root->_left->_value))
			_nil->_left = new_node;
		if (_nil->_right == nullptr)
			_nil->_right = new_node;
		else if (_compare(_nil->_right->_value, val))
			_nil->_right = new_node;
		if (_root == nullptr) {
			_root = new_node;
			new_node->_parent = _nil;
		}
		else {
			node_pointer tmp = _root;
			node_pointer prev = _nil;
			while (tmp != _nil) {
				prev = tmp;
				if (_compare(val, tmp->_value))
					tmp = tmp->_left;
				else if (_compare(tmp->_value, val))
					tmp = tmp->_right;
				else
					break; // memory leak!!!!
			}
			new_node->_parent = prev;
			if (_compare(val, prev->_value))
					prev->_left = new_node;
			else if (_compare(prev->_value, val))
					prev->_right = new_node;
		}
		balanced_after_added(new_node);
		++_size;
	}

	void erase(const value_type& val) {
		node_pointer s = search(val);
		deleted(s);
	}

	void balanced_after_added(node_pointer& node) {
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

	node_pointer search(const value_type& val) {
		node_pointer tmp = _root;
		while (tmp != _nil) {
			if (_compare(val, tmp->_value))
				tmp = tmp->_left;
			else if (_compare(tmp->_value, val))
				tmp = tmp->_right;
			else
				return tmp;
		}
		return (tmp);
	}

	void transplant(node_pointer &u, node_pointer& v) {
		if (u->_parent == _nil) {
			_root = v;
		}
		else if (u == u->_parent->_left)
			u->_parent->_left = v;
		else
			u->_parent->_right = v;
		v->_parent = u->_parent;
	}

	node_pointer tree_min(node_pointer& node) {
		node_pointer rez = node;
		while (rez->_left != _nil)
			rez = rez->_left;
		return (rez);
	}

	void deleted(node_pointer &node) {
		node_pointer del = node;
		node_pointer tmp;
		bool del_red = tmp->_red;
		if (node->_left == _nil) {
			tmp = node->_right;
			transplant(node, node->_right);
		}
		else if (node->_right == _nil) {
			tmp = node->_left;
			transplant(node, node->_left);
		}
		else {
			del= tree_min(node->_right);
			del_red = del->_red;
			tmp = del->_right; 
			if (del->_parent == node)
				tmp->_parent = del;
			else {
				transplant(del, del->_right);
				del->_right = node->_right;
				del->_right->_parent = del;
			}
			transplant(node, del);
			del->_left = node->_left;
			del->_left->_parent = del;
			del->_red = node->_red;
		}
		if (!del_red)
			balanced_after_deleted(tmp);
	}

	void balanced_after_deleted(node_pointer& node) {
		node_pointer brother;
		while (node != _root && !node->_red) {
			if (node == node->_parent->_left) { 
				brother = node->_parent->_right;
				if (brother->_red) {
					brother->_red = false;
					node->_parent->_red = true;
					rotate_left(node->_parent);
					brother = node->_parent->_right;
				}
				if (!brother->_left->_red && !brother->_right->_red) {
					brother->_red = true;
					node = node->_parent;
				}
				else {
					if (!brother->_right->_red) {
						brother->_left->_red = false;
						brother->_red = true;
						rotate_right(brother);
						brother = node->_parent->_right; 
					}
					brother->_red = brother->_parent->_red;
					node->_parent->_red = false; 
					brother->_right->_red = false;
					rotate_left(node->_parent); 
					node = _root;
				}
			}
			else {
				brother = node->_parent->_left; 
				if (brother->_red) {
					brother->_red = false;
					node->_parent->_red = true;
					rotate_right(node->_parent); 
					brother = node->_parent->_left;
				}
				if (!brother->_left->_red && !brother->_right->_red) {
					brother->_red = true;
					node = node->_parent;
				}
				else {
					if (!brother->_left->_red) {
						brother->_right->_red = false;
						brother->_red = true;
						rotate_left(brother);
						brother = node->_parent->_left; 
					}
					brother->_red = brother->_parent->_red;
					node->_parent->_red = false; 
					brother->_left->_red = false;
					rotate_right(node->_parent); 
					node = _root;
				}
			}
		}
		node->_red = false;
	}

	void free_node(node_pointer &node) {
		_allocator.destroy(node);
		_allocator.deallocate(node, 1);
	}

	void rotate_left(node_pointer n) {
		node_pointer son = n->_right;
		n->_right = son->_left;
		if (son->_left != _nil)
			son->_left->_parent = n;
		son->_parent = n->_parent;
		if (n->_parent == _nil)
			_root = son;
		else if (n->_parent->_left == n)
			n->_parent->_left = son;
		else
			n->_parent->_right = son;
		son->_left = n;
		n->_parent = son;
	}

	void rotate_right(node_pointer n) {
		node_pointer son = n->_left;
		n->_left = son->_right;
		if (son->_right != _nil)
			son->_right->_parent = n;
		son->_parent = n->_parent;
		if (n->_parent == _nil)
			_root = son;
		else if (n->_parent->_right == n)
			n->_parent->_right = son;
		else
			n->_parent->_left = son;
		son->_right = n;
		n->_parent = son;
	}

	void print_tree_rec(const node_pointer &tmp) const {
		if (tmp == _nil)
			return ;
		print_tree_rec(tmp->return_left());
		tmp->print_node();
		std::cout << "Address: " << tmp << std::endl << "***********************************************************************************************\n";
		print_tree_rec(tmp->return_right());
	}

	void print_tree() const {
		std::cout << "\n\n******************************************** root *********************************************\n" << "root: " << this->_root << "            nil: " << this->_nil << "\n***********************************************************************************************\n";
		print_tree_rec(this->_root);
		std::cout << "****************************************** min max ********************************************\n" <<  "min: " << this->_nil->_left << "            max: " << this->_nil->_right  << "\n***********************************************************************************************\n";
	}
};

}

#endif