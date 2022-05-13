#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iostream>

namespace ft{

/*********************************************/
/************** std::iterator ****************/
/*********************************************/

template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
    typedef T			value_type;
    typedef Distance	difference_type;
    typedef Pointer		pointer;
    typedef Reference	reference;
    typedef Category	iterator_category;
};

template <typename Iterator>
struct iterator_traits {
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer			pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::iterator_category		iterator_category;
};

/*********************************************/
/*********** Iterator for vector *************/
/*********************************************/

template <typename U>
class IteratorVector : iterator<std::random_access_iterator_tag, U> {
public:
	typedef U																			iterator_type;
	typedef typename iterator<std::random_access_iterator_tag, U>::value_type			value_type;
	typedef typename iterator<std::random_access_iterator_tag, U>::difference_type		difference_type;
	typedef typename iterator<std::random_access_iterator_tag, U>::pointer				pointer;
	typedef typename iterator<std::random_access_iterator_tag, U>::reference			reference;
	typedef typename iterator<std::random_access_iterator_tag, U>::iterator_category	iterator_category;
private:
	pointer _pointer;
public:
	IteratorVector() : _pointer(nullptr) {}
	IteratorVector(pointer p) : _pointer(p) {}
	template <typename _U>
	IteratorVector(const IteratorVector<_U>& it) : _pointer(&(*it)) {}
	~IteratorVector() {}
	IteratorVector& operator=(const IteratorVector& it) {
		if (this == &it) return *this;
		_pointer = it._pointer;
		return *this;
	}
	reference operator*() {return *_pointer; }
	const reference operator*() const {return *_pointer; }
	pointer operator->() {return _pointer; }
	reference operator[](difference_type i) { return *(_pointer + i); }
	IteratorVector& operator++() { ++_pointer; return *this; }
	IteratorVector operator++(int) { IteratorVector copy(*this); ++_pointer; return copy; }
	IteratorVector& operator--() { --_pointer; return *this; }
	IteratorVector operator--(int) { IteratorVector copy(*this); --_pointer; return copy; } 
	IteratorVector& operator+=(const difference_type& i) { _pointer += i; return *this; }
	IteratorVector& operator-=(const difference_type& i) { _pointer -= i; return *this; }
	IteratorVector operator+(const difference_type& i) const { IteratorVector copy; copy += i; return copy; }
	IteratorVector operator-(const difference_type& i) const { IteratorVector copy; copy -= i; return copy; }

	template <typename T1, typename T2> 
	friend bool operator==(const IteratorVector<T1>& x, const IteratorVector<T2>& y) { return x._pointer == y._pointer; }
	template <typename T1, typename T2> 
	friend bool operator!=(const IteratorVector<T1>& x, const IteratorVector<T2>& y) { return !(x._pointer == y._pointer); }
	template <typename T1, typename T2> 
	friend bool operator<(const IteratorVector<T1>& x, const IteratorVector<T2>& y) { return x._pointer < y._pointer; }
	template <typename T1, typename T2> 
	friend bool operator>(const IteratorVector<T1>& x, const IteratorVector<T2>& y) { return y._pointer < x._pointer; }
	template <typename T1, typename T2> 
	friend bool operator<=(const IteratorVector<T1>& x, const IteratorVector<T2>& y) { return !(y._pointer < x._pointer); }
	template <typename T1, typename T2> 
	friend bool operator>=(const IteratorVector<T1>& x, const IteratorVector<T2>& y) { return !(x._pointer < y._pointer); }
};

/*********************************************/
/************* Reverse Iterator **************/
/*********************************************/

// template <typename Iterator>
// class ReverseIterator {
// public:
// 	typedef Iterator												iterator_type;
// 	typedef typename iterator_traits<Iterator>::value_type			value_type;
// 	typedef typename iterator_traits<Iterator>::pointer				pointer;
// 	typedef typename iterator_traits<Iterator>::reference			reference;
// 	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
// 	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
// private:
// 	Iterator iter;
// public:
	// ReverseIteratorVector() : iter() {}
	// ReverseIteratorVector(pointer p) : _pointer(p) {}
	// template <typename _U>
	// ReverseIteratorVector(const ReverseIteratorVector<_U>& it) : _pointer(&(*it)) {}
	// ~ReverseIteratorVector() {}
	// template <typename _U>
	// ReverseIteratorVector& operator=(const ReverseIteratorVector<_U>& it) {
	// 	if (it == *this) return *this;
	// 	_pointer = it._pointer;
	// 	return *this;
	// }

	// reference operator*() {return *_pointer; }
	// const reference operator*() const {return *_pointer; }
	// pointer operator->() {return _pointer; }
	// reference operator[](difference_type i) { return *(_pointer + i); }

	// ReverseIteratorVector& operator++() {
	// 	--_pointer;
	// 	return *this;
	// }
	// ReverseIteratorVector operator++(int) {
	// 	ReverseIteratorVector copy(*this);
	// 	--_pointer;
	// 	return copy;
	// }
	// ReverseIteratorVector& operator--() {
	// 	++_pointer;
	// 	return *this;
	// }
	// ReverseIteratorVector operator--(int) {
	// 	ReverseIteratorVector copy(*this);
	// 	++_pointer;
	// 	return copy;
	// }

	// ReverseIteratorVector operator+(const difference_type& i) const { return _pointer - i; }
	// ReverseIteratorVector& operator+=(const difference_type& i) const { _pointer -= i; return *this; }
	// ReverseIteratorVector operator-=(const difference_type& i) const { _pointer += i; return *this; }
	// ReverseIteratorVector operator-(const difference_type& i) const { return _pointer + i; }

// }; // End Reverse Iterator

}

#endif