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
	bool			_nil;

	explicit redBlackTreeNode(node_pointer& nil, const value_type &val = value_type())
		: _value(val), _left(nil), _right(nil), _parent(nullptr), _red(true), _nil(false) {}

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

	node_pointer tree_min()  {
		node_pointer node = this;
		while (!node->_left->_nil)
			node = node->_left;
		return (node);
	}

	node_pointer tree_max()  {
		node_pointer node = this;
		while (!node->_right->_nil)
			node = node->_right;
		return (node);
	}

	node_pointer increment() {
		node_pointer node = this;
		if (node->_nil)
			return node->_left;
		if (!node->_right->_nil)
			return node->_right->tree_min();
		node_pointer next = node->_parent;
		while (!next->_nil && node == next->_right) {
			node = next;
			next = next->_parent;
		}
		return next;
	}

	node_pointer dicrement() {
		node_pointer node = this;
		if (node->_nil)
			return node->_right;
		if (!node->_left->_nil)
			return node->_left->tree_max();
		node_pointer prev = node->_parent;
		while (!prev->_nil && node == prev->_left) {
			node = prev;
			prev = prev->_parent;
		}
		return prev;
	}

	void print_node() {
		std::cout << "==> This Node is ";
		if (_red == true)
			std::cout << "RED <==\n";
		else
			std::cout << "BLACK <==\n";
		std::cout << "==>first: " << _value.first << " second: " << _value.second << " <==\n";
		// std::cout << "==>VALUE: " << _value << " <==\n";
		std::cout << "==>left: " << _left << " right: " << _right << " parent: " << _parent << " <==Adress: " << this << std::endl << "---------" << std::endl;
	}
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
	typedef IteratorTree<value_type>	iterator;
	typedef IteratorTree<const value_type>	const_iterator;
private:
	node_allocator	_allocator;	
	value_compare	_compare;
	node_pointer	_root;
	node_pointer	_nil;
	size_type		_size;
public:
	/*********************************************/
	/************ Constr and destr ***************/
	/*********************************************/

	explicit redBlackTree(value_compare comp = value_compare())
		: _allocator(node_allocator()), _compare(comp), _root(nullptr), _nil(_allocator.allocate(1)), _size(0) {
		put_in_nil();
	}

	redBlackTree(const redBlackTree& other)
		: _allocator(other._allocator), _compare(other._compare), _root(nullptr), _nil(_allocator.allocate(1)), _size(0) {
		put_in_nil();
		if (other.size() != 0) {
			clone_tree(_root, other._root);
			_size = other._size;
			put_min_max();
		}
	}

	redBlackTree& operator=(const redBlackTree& other) {
		clear_tree();
		_allocator = other._allocator;
		_compare = other._compare;
		put_in_nil();
		if (other.size() == 0) return *this;
		clone_tree(_root, other._root);
		_size = other._size;
		put_min_max();
		return *this;
	}

	~redBlackTree() {
		clear_tree();
		_allocator.deallocate(_nil, 1);
	}

	/*********************************************/
	/************* return members ****************/
	/*********************************************/

	size_type size() const { return _size; }
	node_allocator alloc() const { return _allocator; }

	iterator begin() { return (_nil->_left); }
	iterator end() {return (_nil->_right->_right); }
	const_iterator begin() const { return (_nil->_left); }
	const_iterator end() const { return (_nil->_right->_right); }

	/*********************************************/
	/*************** do members ******************/
	/*********************************************/

	node_pointer search(const value_type& val) const {
		if (_root == nullptr) return _nil;
		node_pointer tmp = _root;
		while (tmp != _nil) {
			if (_compare(val, tmp->_value))
				tmp = tmp->_left;
			else if (_compare(tmp->_value, val))
				tmp = tmp->_right;
			else
				return tmp;
		}
		return (_nil);
	}

	pair<iterator, bool> insert(const value_type& val) {
		return (add(val));
	}

	iterator insert(iterator hint, const value_type& val) {
		if (hint != iterator(_nil)) {
			if (hint == iterator(_nil->_left) && _compare(val, _nil->_left->_value)) {
				node_pointer new_node = _allocator.allocate(1);
				_allocator.construct(new_node, _nil, val);
				new_node->_parent = _nil->_left;
				new_node->_parent->_left = new_node;
				balanced_after_added(new_node);
				++_size;
				return new_node;
			}
			else if (hint == iterator(_nil->_right) && _compare(_nil->_right->_value, val)) {
				node_pointer new_node = _allocator.allocate(1);
				_allocator.construct(new_node, _nil, val);
				new_node->_parent = _nil->_right;
				new_node->_parent->_right = new_node;
				balanced_after_added(new_node);
				++_size;
				return new_node;
			}
		}
		return add(val).first;
	}

	template <typename InputIt>
	typename enable_if<!is_integral<InputIt>::value, void>::type insert(InputIt first, InputIt last) {
		for(; first != last; ++first)
			insert(*first);
	}

	void erase(iterator pos) {
		if (_size == 0) return;
		node_pointer s = static_cast<node_pointer>(pos);
		if (s == _nil) return;
		deleted(s);
	}

	size_type erase(const value_type& val) {
		if (_size == 0) return 0;
		node_pointer s = search(val);
		if (s == _nil) {
			return 0;
		}
		deleted(s);
		return (1);
	}

	void erase(iterator first, iterator last) {
		if (_size == 0) return;
		iterator tmp = first;
		++first;
		for(; first != last; ++first)
		{
			erase(tmp);	
			tmp = first;
		}
		erase(tmp);
	}

	void clear_tree() {
		if (_size == 0) return;
		free_tree(_root);
		put_in_nil();
		_size = 0;
	}

	node_pointer lower_bound(const value_type& val) {
		node_pointer min = _nil;
		for (node_pointer tmp = _nil->_left; tmp != _nil; tmp = tmp->increment()) {
			if (!_compare(tmp->_value, val)) {
				min = tmp;
				break;
			}
		}
		return min;
	}

	node_pointer upper_bound(const value_type& val) {
		node_pointer max = search(val);
		for (node_pointer tmp = _nil->_left; tmp != _nil; tmp = tmp->increment()) {
			if (_compare(val, tmp->_value)) {
				max = tmp;
				break;
			}
		}
		return max;
	}

private:
	/*********************************************/
	/************** ADD in Tree ******************/
	/*********************************************/

	pair<iterator, bool> add(const value_type& val) {
		node_pointer new_node = _allocator.allocate(1);
		_allocator.construct(new_node, _nil, val);
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
				else {
					_allocator.destroy(new_node);
					_allocator.deallocate(new_node, 1);
					return (ft::make_pair<iterator, bool>(tmp, false));
				}
			}
			new_node->_parent = prev;
			if (_compare(val, prev->_value))
					prev->_left = new_node;
			else if (_compare(prev->_value, val))
					prev->_right = new_node;
		}
		balanced_after_added(new_node);
		++_size;
		put_min_max();
		return (ft::make_pair<iterator, bool>(new_node, true));
	}

	void balanced_after_added(node_pointer& node) {
		while (node->_parent && node->_parent->_red) {
			if (node->grandparent() && (node->grandparent())->_left == node->_parent) {
				if (node->uncle() && (node->uncle())->_red) {
					(node->uncle())->_red = false;
					node->_parent->_red = false;
					(node->grandparent())->_red = true;
					node = node->grandparent();
				}
				else {
					if (node->_parent->_right == node) {
						node = node->_parent;
						rotate_left(node);
					}
					node->_parent->_red = false;
					(node->grandparent())->_red = true;
					rotate_right(node->grandparent());
				}
			}
			else {
				if (node->uncle() && (node->uncle())->_red) {
					(node->uncle())->_red = false;
					node->_parent->_red = false;
					(node->grandparent())->_red = true;
					node = node->grandparent();
				}
				else {
					if (node->_parent->_left == node) {
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

	/*********************************************/
	/************** DEL in Tree ******************/
	/*********************************************/

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

	void deleted(node_pointer &node) {
		node_pointer del = node;
		node_pointer freeNode = del;
		node_pointer tmp;
		bool del_red = del->_red;
		if (node->_left == _nil) {
			tmp = node->_right;
			transplant(node, node->_right);
		}
		else if (node->_right == _nil) {
			tmp = node->_left;
			transplant(node, node->_left);
		}
		else {
			del = node->_right->tree_min();
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
		_allocator.destroy(freeNode);
		_allocator.deallocate(freeNode, 1);
		--_size;
		if (_size == 0)
			_root = nullptr;
		put_min_max();
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

	/*********************************************/
	/************* ROTATE in Tree ****************/
	/*********************************************/

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

	/*********************************************/
	/************* HELPER in Tree ****************/
	/*********************************************/

	void clone_tree(node_pointer &_root, const node_pointer& other_root) {
		try {
			_root = _allocator.allocate(1);
			_allocator.construct(_root, _nil, other_root->_value);
			_root->_parent = _nil;
			_nil->_left = _root;
			_nil->_right = _root;
			_root->_red = false;
			clone_children(_root, other_root);
		}
		catch (...) {
			clear_tree();
			throw;
		}
	}

	void clone_children(node_pointer &to, node_pointer from) {
		if (!from->_left->_nil) {
			node_pointer new_node = _allocator.allocate(1);
			_allocator.construct(new_node, _nil, from->_left->_value);
			new_node->_red = from->_left->_red;
			to->_left = new_node;
			to->_left->_parent = to;
			clone_children(to->_left, from->_left);
		}
			if (!from->_right->_nil) {
			node_pointer new_node = _allocator.allocate(1);
			_allocator.construct(new_node, _nil, from->_right->_value);
			new_node->_red = from->_right->_red;
			to->_right = new_node;
			to->_right->_parent = to;
			clone_children(to->_right, from->_right);	
		}
	}

	void free_tree(node_pointer tmp) {
		if (tmp == _nil)
			return ;
		free_tree(tmp->_left);
		free_tree(tmp->_right);
		tmp->_parent = _nil; //may be it delete
		_allocator.destroy(tmp);
		_allocator.deallocate(tmp, 1);
	}

	void put_in_nil() {
		_nil->_parent = nullptr;
		_nil->_right = _nil;
		_nil->_left = _nil;
		_nil->_red = false;
		_nil->_nil = true;
	}

	void put_min_max() {
		node_pointer tmp = _root;
		if (tmp == nullptr) {
			_nil->_left = _nil;
			_nil->_right = _nil;
			return;
		}
		while (tmp->_left != _nil)
			tmp = tmp->_left;
		_nil->_left = tmp;
		tmp = _root;
		while (tmp->_right != _nil)
			tmp = tmp->_right;
		_nil->_right = tmp;
	}

public:
	void print_tree_rec(const node_pointer &tmp) const {
		if (tmp == _nil)
			return ;
		print_tree_rec(tmp->_left);
		tmp->print_node();
		print_tree_rec(tmp->_right);
	}

	void print_tree() const {
		std::cout << "\n\n*** root ***\n" << "root: " << this->_root << " nil: " << this->_nil << "\n     ***     \n";
		if (_size != 0)
			print_tree_rec(this->_root);
		std::cout << "*** min max ***\n" <<  "min: " << this->_nil->_left << " max: " << this->_nil->_right  << "\n     ***     \n";
	}
};

}

#endif