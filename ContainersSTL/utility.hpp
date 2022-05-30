#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>

namespace ft {

/*********************************************/
/***************** iterator ******************/
/*********************************************/

template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
    typedef T		value_type;
    typedef Distance	difference_type;
    typedef Pointer	pointer;
    typedef Reference	reference;
    typedef Category	iterator_category;
};

/*********************************************/
/************* iterator_traits ***************/
/*********************************************/

template <typename Iterator>
struct iterator_traits {
	typedef typename Iterator::value_type		value_type;
	typedef typename Iterator::pointer		pointer;
	typedef typename Iterator::reference		reference;
	typedef typename Iterator::difference_type	difference_type;
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::pointer		iterator_type;
}

template <typename T>
struct iterator_traits<T*> {
	typedef T					value_type;
	typedef T*					pointer;
	typedef T&					reference;
	typedef std::ptrdiff_t				difference_type;
	typedef std::random_access_iterator_tag		iterator_category;
};

template <typename T>
struct iterator_traits<const T*> {
	typedef T					value_type;
	typedef T*					pointer;
	typedef T&					reference;
	typedef std::ptrdiff_t				difference_type;
	typedef std::random_access_iterator_tag		iterator_category;
};


/*********************************************/
/***************** is same *******************/
/*********************************************/

template <typename T, typename U>				
struct is_same { static const bool value = false; };												

template <typename T>						
struct is_same <T, T> { static const bool value = true; };											

/*********************************************/
/**************** enable if ******************/
/*********************************************/

template <bool conditional, typename Type = void>
struct enable_if;			

template <typename Type>			
struct enable_if<true, Type> { typedef Type type; };

/*********************************************/
/*************** is integral *****************/
/*********************************************/

template<class T, T v>
struct integral_constant {
    static const T value = v;
	typedef T value_type;
	typedef integral_constant type;
    operator value_type() const { return value; }
};

struct true_type : integral_constant<bool, true> {};
struct false_type : integral_constant<bool, false> {};


template <class T>
struct is_integral			: false_type {};
template <>
struct is_integral<bool>		: true_type {};
template <>
struct is_integral<unsigned char>	: true_type {};
template <>
struct is_integral<signed char>		: true_type {};
template <>
struct is_integral<char>		: true_type {};
template <>
struct is_integral<char16_t>		: true_type {};
template <>
struct is_integral<char32_t>		: true_type {};
template <>
struct is_integral<wchar_t>		: true_type {};
template <>
struct is_integral<signed short>	: true_type {};
template <>
struct is_integral<unsigned short>	: true_type {};
template <>
struct is_integral<signed int>		: true_type {};
template <>
struct is_integral<unsigned int>	: true_type {};
template <>
struct is_integral<signed long>		: true_type {};
template <>
struct is_integral<unsigned long>	: true_type {};
template <>
struct is_integral<signed long long>	: true_type {};
template <>
struct is_integral<unsigned long long>	: true_type {};

/*********************************************/
/***************** compare *******************/
/*********************************************/

template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
	for (; first1 != last1; ++first1, ++first2) {
		if (!(*first1 == *first2))
			return false;
	}
	return true;
}

template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void)++first2 ) {
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return (first1 == last1) && (first2 != last2);
}

/*********************************************/
/******************* pair ********************/
/*********************************************/

template <typename T1, typename T2>
struct pair {
	typedef T1 first_type;
    	typedef T2 second_type;

	T1	first;
	T2	second;
	
	pair() : first(), second() {}
	pair(const T1& x, const T2& y): first(x), second(y) {}
	// pair(const T1& x): first(x), second() {}
	template <typename U1, typename U2>
	pair(const pair<U1, U2>& p): first(p.first), second(p.second) {}
	pair& operator=(const pair& other) {
		first = other.first;
		second = other.second;
		return (*this);
	}
};

template <typename T1, typename T2>
ft::pair<T1, T2> make_pair(T1 t, T2 u) {
	ft::pair<T1, T2> rez(t, u);
	return (rez);
}

template <typename T1, typename T2>
bool operator==(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
	return x.first  == y.first && x.second == y.second;
}

template <typename T1, typename T2>
bool operator!=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
	return !(x == y);
}

template <typename T1, typename T2>
bool operator<(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
	return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template <typename T1, typename T2>
bool operator>(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
	return y < x;
}

template <typename T1, typename T2>
bool operator>=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
	return !(x < y);
}

template <typename T1, typename T2>
bool operator<=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
	return !(y < x);
}

template <typename T, typename Allocator> class vector;
template <class Key, class T, class Compare, class Allocator> class map;
template <class Key, class Compare, class Allocator> class set;
	
}

namespace std {
	
template <class T, class A>
void swap(ft::vector<T, A> &v1, ft::vector<T, A> &v2 ) {
	v1.swap(v2);
}

template <class K, class T, class C, class A>
void swap(ft::map<K, T, C, A> &v1, ft::map<K, T, C, A> &v2 ) {
	v1.swap(v2);
}

template <class K, class C, class A>
void swap(ft::set<K, C, A> &v1, ft::set<K, C, A> &v2 ) {
	v1.swap(v2);
}	
	
}

#endif
