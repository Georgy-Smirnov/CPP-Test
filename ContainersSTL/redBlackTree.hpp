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
	node_pointer	_root;  		// root - фейковая нода, у которой parent - указатель на реальный корень
	node_allocator	_allocator;		// left - указатель на минемальное значение в дереве
	value_compare	_compare;		// right - указатель на максимальное значение в дереве
	size_type		_size;			/// ТАК НЕ РАБОТАЕТ!!!!! добавить нил!
public:
	explicit redBlackTree(value_compare comp = value_compare())
		: _root(nullptr), _allocator(node_allocator()), _compare(comp), _size(0) {
		_root = _allocator.allocate(1);
		_root->_parent = nullptr;
		_root->_right = nullptr;
		_root->_left = nullptr;
		_root->_red = false;
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
		_allocator.construct(new_node, _root, val);
		if (_root->_left == nullptr)
			_root->_left = new_node;
		else if (_compare(val, _root->_left->_value))
			_root->_left = new_node;
		if (_root->_right == nullptr)
			_root->_right = new_node;
		else if (_compare(_root->_right->_value, val))
			_root->_right = new_node;
		if (_root->_parent == nullptr) {
			_root->_parent = new_node;
			new_node->_parent = _root;
		}
		else {
			node_pointer tmp = _root->_parent;
			node_pointer prev = _root;
			while (tmp != _root) {
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
		_root->_parent->_red = false;
	}

	node_pointer search(const value_type& val) {
		node_pointer tmp = _root->_parent;
		while (tmp != _root) {
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
		if (u->_parent == _root) {
			_root->_parent = v;
		}
		else if (u == u->_parent->_left)
			u->_parent->_left = v;
		else
			u->_parent->_right = v;
		if (v != _root)
			v->_parent = u->_parent;
	}

	node_pointer tree_min(node_pointer& node) {
		node_pointer rez = node;
		while (rez->_left != _root)
			rez = rez->_left;
		return (rez);
	}

	void deleted(node_pointer &node) {
		node_pointer del = node;
		node_pointer tmp;
		bool del_red = tmp->_red;
		if (node->_left == _root) {
			tmp = node->_right;
			transplant(node, node->_right);
		}
		else if (node->_right == _root) {
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
		while (node != _root->_parent && !node->_red) {
			if (node == node->_parent->_left) { ///не использовать node->_parent
				brother = node->_parent->_right; ///не использовать node->_parent
				if (brother->_red) {
					brother->_red = false;
					node->_parent->_red = true; ///не использовать node->_parent
					rotate_left(node->_parent); ///не использовать node->_parent
					brother = brother->_left->_right;
				}
				if (!brother->_left->_red && !brother->_right->_red) {
					brother->_red = true;
					node = node->_parent; ///не использовать node->_parent
				}
				else {
					if (!brother->_right->_red) {
						brother->_left->_red = false;
						brother->_red = true;
						rotate_right(brother);
						brother = node->_parent->_right; ///не использовать node->_parent
					} 
					brother->_red = brother->_parent->_red;
					node->_parent->_red = false; ///не использовать node->_parent
					brother->_right->_red = false;
					rotate_left(node->_parent); ///не использовать node->_parent
					node = _root->_parent;
				}
			}
			else {
				brother = node->_parent->_left; ///не использовать node->_parent
				if (brother->_red) {
					brother->_red = false;
					node->_parent->_red = true; ///не использовать node->_parent
					rotate_right(node->_parent); ///не использовать node->_parent
					brother = brother->_right->_left;
				}
				if (!brother->_left->_red && !brother->_right->_red) {
					brother->_red = true;
					node = node->_parent; ///не использовать node->_parent
				}
				else {
					if (!brother->_left->_red) {
						brother->_right->_red = false;
						brother->_red = true;
						rotate_left(brother);
						brother = node->_parent->_left; ///не использовать node->_parent
					}
					brother->_red = brother->_parent->_red;
					node->_parent->_red = false; ///не использовать node->_parent
					brother->_left->_red = false;
					rotate_right(node->_parent); ///не использовать node->_parent
					node = _root->_parent;
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
		son->_parent = n->_parent;
		n->_parent = son;
		if (son->_parent != _root) {
			if (son->_parent->_left == n)
				son->_parent->_left = son;
			else
				son->_parent->_right = son;
		}
		else
			_root->_parent = son;
		n->_right = son->_left;
		if (son->_left != _root)
			n->_right->_parent = n;
		n->_parent = son;
		son->_left = n;
	}

	void rotate_right(node_pointer n) {
		node_pointer son = n->_left;
		son->_parent = n->_parent;
		if (n->_parent != _root) {
			if (n->_parent->_left == n)
				n->_parent->_left = son;
			else
				n->_parent->_right = son;
		}
		else
			_root->_parent = son;
		n->_left = son->_right;
		if (son->_right != _root)
			n->_left->_parent = n;
		n->_parent = son;
		son->_right = n;
	}

	node_pointer& first() {
		node_pointer tmp = _root;
		while (tmp->_left)
			tmp = tmp->_left;
		return tmp;
	}

	node_pointer& last() {
		node_pointer tmp = _root;
		while (tmp->_right)
			tmp = tmp->_right;
		return tmp;
	}

	void print_tree_rec(const node_pointer &tmp) const {
		if (tmp == _root)
			return ;
		print_tree_rec(tmp->return_left());
		tmp->print_node();
		std::cout << "Address: " << tmp << std::endl << "***********************************************************************************************\n";
		print_tree_rec(tmp->return_right());
	}

	void print_tree() const {
		std::cout << "\n\n******************************************** root *********************************************\n" << "root: " << this->_root << "            real_root: " << this->_root->_parent << "\n***********************************************************************************************\n";
		print_tree_rec(this->_root->_parent);
		std::cout << "****************************************** min max ********************************************\n" <<  "min: " << this->_root->_left << "            max: " << this->_root->_right  << "\n***********************************************************************************************\n";
	}
};

}

#endif