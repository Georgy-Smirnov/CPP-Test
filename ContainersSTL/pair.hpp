#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft{

template <typename T1, typename T2>
struct pair {
	typedef T1 first_type;
    typedef T2 second_type;

	T1	first;
	T2	second;
	pair() : first(), second() {}
	pair(const T1& x, const T2& y): first(x), second(y) {}
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

}

#endif