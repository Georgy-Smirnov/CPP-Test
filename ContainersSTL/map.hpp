#ifndef MAP_HPP
#define MAP_HPP

#include "utility.hpp"
#include "iterators.hpp"
#include "redBlackTree.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
class map {
public:
	/*********************************************/
	/*************** Member types ****************/
	/*********************************************/

	typedef Key												key_type;
	typedef T												mapped_type;
	typedef pair<const key_type, mapped_type>				value_type;
	typedef std::size_t										size_type;
	typedef std::ptrdiff_t									difference_type;
	typedef Compare											key_compare;
	typedef Allocator										allocator_type;
	typedef value_type&										reference;
	typedef const value_type&								const_reference;
	typedef typename Allocator::pointer						pointer;
	typedef typename Allocator::const_pointer				const_pointer;
	typedef IteratorTree<value_type>						iterator;
	typedef IteratorTree<const value_type>					const_iterator;
	typedef ReverseIterator<iterator>		reverse_iterator;
	typedef ReverseIterator<const_iterator>	const_reverse_iterator;
private:

	/*********************************************/
	/************** Member classes ***************/
	/*********************************************/

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

	typedef redBlackTree<value_type, value_compare, allocator_type> tree;

	value_compare _compare;
	tree _tree;
public:
	/*********************************************/
	/************* Member functions **************/
	/*********************************************/

	map() : _compare(key_compare()), _tree(_compare) {}

	explicit map(const Compare& comp, const Allocator& alloc = Allocator()) : _compare(comp), _tree(_compare) {}

	template< class InputIt >
	map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _compare(comp), _tree(_compare) {
		for (InputIt i = first; i != last; ++i) {
			_tree.insert(*i);
		}
	}

	map(const map& other) : _compare(other._compare), _tree(other._tree) {}
	
	~map() {}

	map& operator=(const map& other) {
		if (&other == this) return *this;
		_compare = other._compare;
		_tree = other._tree;
		return *this;
	}

	allocator_type get_allocator() const { return _tree.alloc(); }

	/*********************************************/
	/************** Element access ***************/
	/*********************************************/

	mapped_type& at(const key_type& key) {
		if (_tree.search(ft::make_pair<key_type, mapped_type>(key, mapped_type())) == nullptr)
			throw (std::out_of_range("map"));
		return ((_tree.search(ft::make_pair<key_type, mapped_type>(key, mapped_type())))->_value).second;
	}
		
	const mapped_type& at(const key_type& key) const {
		if (_tree.search(ft::make_pair<key_type, mapped_type>(key, mapped_type())) == nullptr)
			throw (std::out_of_range("map"));
		return ((_tree.search(ft::make_pair<key_type, mapped_type>(key, mapped_type())))->_value).second;
	}

	mapped_type& operator[](const key_type& key) {
		return ((_tree.search(ft::make_pair<key_type, mapped_type>(key, mapped_type())))->_value).second;
	}

	/*********************************************/
	/**************** Iterators ******************/
	/*********************************************/

	iterator begin() { return _tree.begin(); }
	const_iterator begin() const { return _tree.begin(); }
	iterator end() { return _tree.end(); }
	const_iterator end() const { return _tree.end(); }
	
	reverse_iterator rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
	reverse_iterator rend() { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

	/*********************************************/
	/***************** Capacity ******************/
	/*********************************************/

	bool empty() const { return !(_tree.size()); }

	size_type size() const { return _tree.size(); }

	size_type max_size() const { return get_allocator().max_size(); }

	/*********************************************/
	/**************** Modifiers ******************/
	/*********************************************/

	void clear() { _tree.clear_tree(); }

	// std::pair<iterator, bool> insert(const value_type& value);

	// iterator insert(iterator hint, const value_type& value);

	// template< class InputIt >
	// void insert( InputIt first, InputIt last );

	void insert(value_type val) {
		_tree.insert(val);
	}

	// void erase( iterator pos );
	// void erase( iterator first, iterator last );
	// size_type erase( const Key& key );

	// void swap( map& other );

	/*********************************************/
	/***************** LookUp ********************/
	/*********************************************/

	size_type count( const Key& key ) const {
		if ((_tree.search(ft::make_pair<key_type, mapped_type>(key, mapped_type())))->_nil)
			return (0);
		return (1);
	}

	iterator find(const key_type& key) { return _tree.search(ft::make_pair<key_type, mapped_type>(key, mapped_type())); }
	const_iterator find(const key_type& key) const { return _tree.search(ft::make_pair<key_type, mapped_type>(key, mapped_type())); }

	iterator lower_bound(const key_type& key) { return _tree.lower_bound(ft::make_pair<key_type, mapped_type>(key, mapped_type())); }
	const_iterator lower_bound(const key_type& key) const { return _tree.lower_bound(ft::make_pair<key_type, mapped_type>(key, mapped_type())); }
	
	iterator upper_bound(const key_type& key) { return _tree.upper_bound(ft::make_pair<key_type, mapped_type>(key, mapped_type())); }
	const_iterator upper_bound(const key_type& key) const { return _tree.upper_bound(ft::make_pair<key_type, mapped_type>(key, mapped_type())); }


	// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	// pair<iterator,iterator>             equal_range (const key_type& k);

	/*********************************************/
	/**************** Observers ******************/
	/*********************************************/	

	//key_comp

	//value_comp	

	/*********************************************/
	/*********** Non-Member functions ************/
	/*********************************************/

	//operators == != < > <= >=
};
}

#endif