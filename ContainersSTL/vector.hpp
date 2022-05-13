#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterators.hpp"

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector{
public:
	/*********************************************/
	/*************** Member types ****************/
	/*********************************************/

	typedef T					value_type;
	typedef Allocator				allocator_type;
	typedef size_t					size_type;
	typedef std::ptrdiff_t				difference_type;
	typedef value_type&				reference;
	typedef const value_type&			const_reference;
	typedef typename Allocator::pointer		pointer;
	typedef typename Allocator::const_pointer	const_pointer;
	typedef IteratorVector<value_type>			iterator;
	typedef IteratorVector<const value_type>		const_iterator;
	// typedef ReverseIterator<iterator>		reverse_iterator;
	// typedef ReverseIterator<const_iterator>	reverse_const_iterator;

private:
	pointer		_array;
	size_type	_size;
	size_type	_capacity;
	allocator_type	_allocator;
public:
	/*********************************************/
	/************* Member functions **************/
	/*********************************************/

	explicit vector(const allocator_type& alloc = allocator_type())
		: _array(nullptr), _size(0), _capacity(0), _allocator(alloc) {}
	explicit vector(size_type count, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
		: _size(count), _capacity(count), _allocator(alloc) {
		_array = _allocator.allocate(_capacity);
		for (size_t i = 0; i < _size; ++i) {
			try {
				_allocator.construct(_array + i, value);
			}
			catch (std::exception &ex) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(_array + j);
				_allocator.deallocate(_array, _capacity);
				throw;
			}
		}
	}

	template< class InputIt >
	vector(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last, const Allocator& alloc = Allocator())
		: _array(nullptr), _size(0), _capacity(0), _allocator(alloc) {
		if (last < first) return;
		_size = last - first;
		_capacity = _size;
		_array = _allocator.allocate(_capacity);
		for (size_t i = 0; i < _size; ++i) {
			try {
				_allocator.construct(_array + i, *(first + i));
			}
			catch (std::exception &ex) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(_array + j);
				_allocator.deallocate(_array, _capacity);
				throw;
			}
		}
	}

	vector(const vector& other) : _size(other._size), _capacity(other._capacity), _allocator(other._allocator) {
		_array = _allocator.allocate(_capacity);
		for (size_t i = 0; i < _size; ++i) {
			try {
				_allocator.construct(_array + i, other._array[i]);
			}
			catch (std::exception &ex) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(_array + j);
				_allocator.deallocate(_array, _capacity);
				throw;
			}
		}
	}

	~vector() {
		if (_capacity == 0) return;
		for (size_t i = 0; i < _size; ++i)
			_allocator.destroy(_array + i);
		_allocator.deallocate(_array, _capacity);
	}

	vector& operator=(const vector& other) {
		// if (other == *this) return *this;
		pointer tmp = _allocator.allocate(other._capacity);
		for (size_t i = 0; i < other._size; ++i) {
			try {
				_allocator.construct(tmp + i, *(other._array + i));
			}
			catch (std::exception &ex) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(tmp + j);
				_allocator.deallocate(tmp, other._capacity);
				throw;
			}
		}
		for (size_t i = 0; i < _size; ++i)
			_allocator.destroy(_array + i);
		if (_capacity != 0)
			_allocator.deallocate(_array, _capacity);
		_array = tmp;
		_size = other._size;
		_capacity = other._capacity;
		_allocator = other._allocator;
		return *this;
	}

	void assign(size_type count, const value_type& value) {
		reserve(count);
		size_t i = 0;
		while (i < count) {
			_allocator.destroy(_array + i);
			try {
				_allocator.construct(_array + i, value);
			}
			catch (std::exception &ex) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(_array + j);
				throw;
			}
			++i;
		}
		while (i < _size) {
			--_size;
			_allocator.destroy(_array + _size);
		}
		
	}
	
	template< class InputIt >
	void assign(InputIt first, InputIt last) {
		int tmp = last - first;
		reserve(tmp);
		size_t i = 0;
		while (i < tmp) {
			_allocator.destroy(_array + i);
			try {
				_allocator.construct(_array + i, *(first + i));
			}
			catch (std::exception &ex) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(_array + j);
				throw;
			}
			++i;
		}
		while (i < _size) {
			--_size;
			_allocator.destroy(_array + _size);
		}
	}

	allocator_type get_allocator() const { return _allocator; }

	/*********************************************/
	/************** Element access ***************/
	/*********************************************/

	reference at(size_type pos) {
		if (pos >= _size || pos < 0)
			throw (std::out_of_range("Index_vector at out of range"));	
		return *(_array + pos);
	}
	const_reference at(size_type pos) const { 
		if (pos >= _size || pos < 0)
			throw (std::out_of_range("Index_vector at out of range"));	
		return *(_array + pos);
	}
	reference operator[]( size_type pos ) { return *(_array + pos); }
	const_reference operator[]( size_type pos ) const { return *(_array + pos); }
	reference front() { return *_array; }
	const_reference front() const { return *_array; }
	reference back() { return *(_array + _size - 1); }
	const_reference back() const { return *(_array + _size - 1); }
	value_type* data() { return _array; }
	const value_type* data() const { return _array; }

	/*********************************************/
	/**************** Iterators ******************/
	/*********************************************/

	iterator begin() { return _array; }
	const_iterator begin() const { return _array; }
	iterator end() { return _array + _size; }
	const_iterator end() const { return _array + _size; }
	iterator rbegin() { return _array + _size; }
	const_iterator rbegin() const { return _array + _size; }
	iterator rend() { return _array; }
	const_iterator rend() const { return _array; }

	/*********************************************/
	/***************** Capacity ******************/
	/*********************************************/
	bool empty() const { return _size == 0; }

	size_type size() const { return _size; }

	size_type max_size() const { return _allocator.max_size(); }

	void reserve(size_type new_cap) {
		if (new_cap <= _capacity) return;
		pointer new_array = _allocator.allocate(new_cap);
		for (size_t i = 0; i < _size; ++i) {
			try {
				_allocator.construct(new_array + i, *(_array + i));
			}
			catch (std::exception &ex) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(new_array + j);
				_allocator.deallocate(new_array, _capacity);
				throw;
			}
		}
		if (_capacity != 0) {
			for (size_t i = 0; i < _size; ++i)
				_allocator.destroy(_array + i);
			_allocator.deallocate(_array, _capacity);
		}
		_array = new_array;
		_capacity = new_cap;
	}

	size_type capacity() const { return _capacity; }

	/*********************************************/
	/**************** Modifiers ******************/
	/*********************************************/

	void clear() {
		for (size_t i = 0; i < _size; ++i)
			_allocator.destroy(_array + i);
		_size = 0;
	}

	iterator insert(iterator pos, const T& value) {
		if (pos < this->begin() || pos > this->end()) throw(std::out_of_range("Index_vector at out of range"));
		if (_capacity > _size + 1) {
			size_t j = 0;
			pointer tmp = _allocator.allocate(_capacity);
			for (iterator i = this->begin(); i < pos; ++i) {
				try {
					_allocator.consrtuct(&(*i), *(_array + j));
				}
				catch (std::exception &ex) {
					for (size_t q = 0; q < j; ++q)
						_allocator.destroy(tmp + j)
				}

			}
		}
	}

	// void insert( iterator pos, size_type count, const T& value );
	// template< class InputIt >
	// void insert( iterator pos, InputIt first, InputIt last );
	// iterator erase( iterator pos );
	// iterator erase( iterator first, iterator last );

	void push_back(const value_type& value) {
		if (_size == _capacity) {
			if (_size == 0)	reserve(1);
			else reserve(_capacity * 2);
		}
		_allocator.construct(_array + _size, value);
		++_size;		
	}

	void pop_back() {
		_allocator.destroy(_array + _size - 1);
		--_size;
	}

	void resize(size_type count, value_type value = value_type()) {
		if (count > _size) {
			reserve(count);
			for (size_t i = _size; i < count; ++i) {
				try {
					_allocator.construct(_array + i, value);
				}
				catch (std::exception &ex) {
					for (size_t j = _size; j < i; ++j)
						_allocator.destroy(_array + j);
					throw;
				}
			}
			_size = count;
		}
		else if (count < _size) {
			for (size_t i = count; i < _size; ++i)
				_allocator.destroy(_array + i);
			_size = count;
		}
	}

	void swap( vector& other ) {
		std::swap(_array, other._array);
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
		std::swap(_allocator, other._allocator);
	}

// template< class T, class Alloc >
// bool operator==(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
// template< class T, class Alloc >
// bool operator!=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
// template< class T, class Alloc >
// bool operator<(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
// template< class T, class Alloc >
// bool operator<=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
// template< class T, class Alloc >
// bool operator>(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
// template< class T, class Alloc >
// bool operator>=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
};


} // namespace ft 

#endif
