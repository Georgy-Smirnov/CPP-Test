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
	// typedef IteratorMap<value_type, allocator_type>			iterator;
	// typedef IteratorMap<const value_type, allocator_type>	const_iterator;
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

	map() : _compare(key_compare()), _tree(_compare) {

		// value_compare a = new value_compare();
		// std::cout << _tree(make_pair<int, int>(5, 1), make_pair<int, int>(6, 1)) << "\n";
		// tree tree;
		// std::cout << "Size: " << tree.size() << std::endl;
		// tree.insert(ft::make_pair<int, std::string>(50, "hello"));
		// // std::cout << "Size: " << tree.size() << std::endl;
		// tree.insert(ft::make_pair<int, std::string>(30, "he"));
		// tree.insert(ft::make_pair<int, std::string>(40, "he"));
		// tree.insert(ft::make_pair<int, std::string>(20, "he"));
		// tree.insert(ft::make_pair<int, std::string>(60, "he"));
		// tree.insert(ft::make_pair<int, std::string>(45, "he"));
		// tree.insert(ft::make_pair<int, std::string>(47, "he"));
		// tree.insert(ft::make_pair<int, std::string>(46, "heasdsad"));
		// tree.insert(ft::make_pair<int, std::string>(42, "he"));
		// tree.print_tree();
		// tree.deleted(ft::make_pair<int, std::string>(46, "he"));
		// tree.print_tree();
		// tree.find(5).second = "lol";
		// tree.print_tree();
		
	}
	// explicit map(const Compare& comp, const Allocator& alloc = Allocator()) {}
	// template< class InputIt >
	// map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) {}
	// map(const map& other);
	//destructors

	//operator=

	//get_allocator

	/*********************************************/
	/************** Element access ***************/
	/*********************************************/

	//at

	//operator []

	/*********************************************/
	/**************** Iterators ******************/
	/*********************************************/

	//begin

	//end

	//rbegin

	//rend

	/*********************************************/
	/***************** Capacity ******************/
	/*********************************************/

	//empty

	//size

	//max_size

	/*********************************************/
	/**************** Modifiers ******************/
	/*********************************************/

	//clear

	//insert

	//erase

	//swap

	/*********************************************/
	/***************** LookUp ********************/
	/*********************************************/

	//count

	//find

	//equal_range

	//lower_bound

	//upper_bound

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