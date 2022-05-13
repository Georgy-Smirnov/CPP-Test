// iterator_traits.cpp


// struct iterator_traits {
//    typedef typename Iterator::iterator_category iterator_category;
//    typedef typename Iterator::value_type value_type;
//    typedef typename Iterator::difference_type difference_type;
//    typedef difference_type distance_type;
//    typedef typename Iterator::pointer pointer;
//    typedef typename Iterator::reference reference;
//    };


#include <iostream>
#include <iterator>
#include <vector>
#include <list>

template <typename it>
void function(it begin, it end) {
	typename std::iterator_traits<it>::iterator_category category;
	std::cout << typeid(category).name() << std::endl;
	while (begin != end) {
		typename std::iterator_traits<it>::value_type type;
		type = *begin;
		std::cout << type << " ";
		++begin;
	}
	std::cout << std::endl;
}

int main(void) {
	std::vector<char> vc(10, 'a');
	function<std::vector<char>::iterator>(vc.begin(), vc.end());
	std::list<int> li(10);
	function<std::list<int>::iterator>(li.begin(), li.end());
}

/*NSt3__126random_access_iterator_tagE
a a a a a a a a a a 
NSt3__126bidirectional_iterator_tagE
0 0 0 0 0 0 0 0 0 0 */