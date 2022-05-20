#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft{

template<class T, class Container = ft::vector<T> >
class stack {
	
	typedef Container                                container_type;
    typedef typename container_type::value_type      value_type;
    typedef typename container_type::reference       reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type       size_type;

protected:
	container_type c;

public:
	explicit stack(const container_type& cont = container_type()): c(cont) {}	
	stack(const stack& q) : c(q.c) {}
	~stack() {}	

	stack& operator=(const stack& q) { c = q.c;	return *this; }

	T& top() { return c.back();	}	
	bool empty() const { return c.empty(); }
	int size() const { return c.size(); }	
	void push(const T& value) { c.push_back(value);	}
	void pop() { c.pop_back(); }

	template <class T1, class C1>
	friend bool operator==(const stack<T1, C1>& x, const stack<T1, C1>& y){ return x.c == y.c; }
	template <class T1, class C1>
	friend bool operator!=(const stack<T1, C1>& x, const stack<T1, C1>& y){ return !(x.c == y.c); }
	template <class T1, class C1>
	friend bool operator<(const stack<T1, C1>& x, const stack<T1, C1>& y) { return x.c < y.c; }
	template <class T1, class C1>
	friend bool operator>(const stack<T1, C1>& x, const stack<T1, C1>& y) { return y.c < x.c; }
	template <class T1, class C1>
	friend bool operator>=(const stack<T1, C1>& x, const stack<T1, C1>& y) { return !(x.c < y.c); }
	template <class T1, class C1>
	friend bool operator<=(const stack<T1, C1>& x, const stack<T1, C1>& y) { return !(y.c < x.c); }
};
} // namespace ft 

#endif