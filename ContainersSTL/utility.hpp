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
    typedef T			value_type;
    typedef Distance	difference_type;
    typedef Pointer		pointer;
    typedef Reference	reference;
    typedef Category	iterator_category;
};

/*********************************************/
/************* iterator_traits ***************/
/*********************************************/

template <typename Iterator>
struct iterator_traits {
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer			pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::iterator_category		iterator_category;
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

template <bool conditional, typename Type>
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
struct is_integral				: false_type {};
template <>
struct is_integral<bool>		: true_type {};
template <>
struct is_integral<char>		: true_type {};
template <>
struct is_integral<char16_t>	: true_type {};
template <>
struct is_integral<char32_t>	: true_type {};
template <>
struct is_integral<wchar_t>		: true_type {};
template <>
struct is_integral<short>		: true_type {};
template <>
struct is_integral<int>			: true_type {};
template <>
struct is_integral<long>		: true_type {};
template <>
struct is_integral<long long>	: true_type {};


template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
	for (; first1 != last1; ++first1, ++first2) {
		if (!(*first1 == *first2)) {
			return false;
		}
	}
	return true;
}

template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void)++first2 ) {
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return (first1 == last1) && (first2 != last2);
}

} // namespace ft

#endif