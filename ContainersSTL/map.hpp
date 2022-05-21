#ifndef MAP_HPP
#define MAP_HPP

#include "utility.hpp"
#include "iterators.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
class map {
public:
	/*********************************************/
	/*************** Member types ****************/
	/*********************************************/

	typedef Key									key_type;
	typedef T									mapped_type;
	typedef pair<const Key, T>					value_type;
	typedef std::size_t							size_type;
	typedef std::ptrdiff_t						difference_type;
	typedef Compare								key_compare;
	typedef Allocator							allocator_type;
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef typename Allocator::pointer			pointer;
	typedef typename Allocator::const_pointer	const_pointer;
	typedef IteratorMap<value_type>				iterator;
	typedef IteratorMap<const value_type>		const_iterator;

	/*********************************************/
	/************** Member classes ***************/
	/*********************************************/

	// class value_compare
private:
	typedef redBlackTreeNode<value_type, allocator_type>		node;
	typedef typename Allocator::template rebind<node>::other	node_allocator;
	typedef	typename node_allocator::pointer					node_pointer;
	node_pointer	_root;
	node_pointer	_first;
	node_pointer	_last;
	size_type		_size;
	node_allocator	_allocator;
	//value_compare
public:
	/*********************************************/
	/************* Member functions **************/
	/*********************************************/

	//constructors

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