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
	typedef ReverseIterator<iterator>		reverse_iterator;
	typedef ReverseIterator<const_iterator>	const_reverse_iterator;

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
		: _array(nullptr), _size(count), _capacity(count), _allocator(alloc) {
		_array = _allocator.allocate(_capacity);
		for (size_t i = 0; i < _size; ++i) {
			try {
				_allocator.construct(_array + i, value);
			}
			catch (...) {
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
			catch (...) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(_array + j);
				_allocator.deallocate(_array, _capacity);
				throw;
			}
		}
	}

	vector(const vector& other) : _size(other._size), _capacity(other._capacity), _allocator(other._allocator) {
		if (_capacity == 0) return;
		_array = _allocator.allocate(_capacity);
		for (size_t i = 0; i < _size; ++i) {
			try {
				_allocator.construct(_array + i, other._array[i]);
			}
			catch (...) {
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
		if (other == *this) return *this;
		pointer tmp = _allocator.allocate(other._capacity);
		for (size_t i = 0; i < other._size; ++i) {
			try {
				_allocator.construct(tmp + i, *(other._array + i));
			}
			catch (...) {
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
			catch (...) {
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
		_size = count;
	}
	
	template< class InputIt >
	void assign(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last) {
		unsigned int tmp = last - first;
		reserve(tmp);
		size_t i = 0;
		while (i < tmp) {
			_allocator.destroy(_array + i);
			try {
				_allocator.construct(_array + i, *(first + i));
			}
			catch (...) {
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
		_size = tmp;
	}

	allocator_type get_allocator() const { return _allocator; }

	/*********************************************/
	/************** Element access ***************/
	/*********************************************/

	reference at(size_type pos) {
		if (pos >= _size || pos < 0)
			throw (std::out_of_range("vector"));	
		return *(_array + pos);
	}
	const_reference at(size_type pos) const { 
		if (pos >= _size || pos < 0)
			throw (std::out_of_range("vector"));	
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
	reverse_iterator rbegin() { return reverse_iterator(--end()); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(--end()); }
	reverse_iterator rend() { return reverse_iterator(--begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(--begin()); }

	/*********************************************/
	/***************** Capacity ******************/
	/*********************************************/
	bool empty() const { return !_size; }

	size_type size() const { return _size; }

	size_type max_size() const { return _allocator.max_size(); }

	void reserve(size_type new_cap) {
		if (new_cap <= _capacity) return;
		pointer new_array = _allocator.allocate(new_cap);
		for (size_t i = 0; i < _size; ++i) {
			try {
				_allocator.construct(new_array + i, *(_array + i));
			}
			catch (...) {
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
		if (_capacity == 0) {
			this->push_back(value);
			return iterator(_array);
		}
		if (_capacity >= _size + 1) {
			iterator tmp = this->end();
			while (tmp != pos) {
				try {
					_allocator.construct(&(*tmp), *(tmp - 1));
					_allocator.destroy(&(*(tmp - 1)));
				}
				catch (...) {
					for (iterator j = pos; j != tmp; ++j) {
						_allocator.destroy(&(*j));
					}
					throw;
				}
				--tmp;
			}
			_allocator.construct(&(*pos), value);
			++_size;
			return pos;
		}
		else {
			unsigned int count = pos - this->begin();
			pointer tmp = _allocator.allocate(_capacity * 2);
			for (size_t i = 0; i < count; ++i) {
				try {
					_allocator.construct(tmp + i, *(_array + i));
				}
				catch (...) {
					for (size_t j = 0; j < i; ++j)
						_allocator.destroy(tmp + j);
					_allocator.deallocate(tmp, _capacity * 2);
					throw;
					}
			}
			count = this->size() - (this->end() - pos);
			for (size_t i = this->size(); i > count; --i) {
				try {
					_allocator.construct(tmp + i, *(_array + i - 1));
					_allocator.destroy(tmp + i - 1);
				}
				catch (...) {
					for (size_t j = this->size(); j > i; --j)
						_allocator.destroy(tmp + j);
					_allocator.deallocate(tmp, _capacity * 2);
					throw;
				}
			}
			try {
				_allocator.construct(tmp + count, value);
			}
			catch (...) {
				for (size_t i = _size; i > count; --i)
					_allocator.destroy(tmp + i);
				count = pos - this->begin();
				for (size_t i = 0; i < count; ++i)
					_allocator.destroy(tmp + i);
				_allocator.deallocate(tmp, _capacity * 2);
				throw;
			}
			for (size_t i = 0; i < this->size(); ++i)
				_allocator.destroy(_array + i);
			_allocator.deallocate(_array, _capacity);
			_capacity = _capacity * 2;
			++_size;
			_array = tmp;
			return _array + count;
		}
	}

	void insert(iterator pos, size_type count, const T& value) {
		unsigned int i = 0;
		pointer tmp = nullptr;
		size_type tmp_count = count;
		size_type new_capacity;
		if (_size + count <= _capacity)
			new_capacity = _capacity;
		else if (_size + count <= _capacity * 2)
			new_capacity = _capacity * 2;
		else
			new_capacity = _size + count;
		tmp = _allocator.allocate(new_capacity);
		unsigned int index = pos - this->begin();
		while (i < index) {
			try {
				_allocator.construct(tmp + i, *(_array + i));
			}
			catch (...) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(tmp + j);
				_allocator.deallocate(tmp, new_capacity);
				throw;
			}
			++i;
		}
		while (tmp_count != 0) {
			try {
				_allocator.construct(tmp + index, value);
			}
			catch (...) {
				for (size_t j = 0; j < index; ++j)
					_allocator.destroy(tmp + j);
				_allocator.deallocate(tmp, new_capacity);
				throw;
			}
			++index;
			--tmp_count;
		}
		while (i < this->size()) {
			try {
				_allocator.construct(tmp + index, *(_array + i));
			}
			catch (...) {
				for (size_t j = 0; j < index; ++j)
					_allocator.destroy(tmp + j);
				_allocator.deallocate(tmp, new_capacity);
				throw;
			}
			++index;
			++i;
		}
		for (size_t i = 0; i < this->size(); ++i)
			_allocator.destroy(_array + i);
		_allocator.deallocate(_array, _capacity);
		_capacity = new_capacity;
		_size = _size + count;
		_array = tmp;
	}

	template <typename InputIt>
	typename enable_if<!is_integral<InputIt>::value, void>::type
		insert(iterator pos, InputIt first, InputIt last) {
		unsigned int i = 0;
		pointer tmp = nullptr;
		size_type count = last - first;
		size_type tmp_count = 0;
		size_type new_capacity;
		if (_size + count <= _capacity)
			new_capacity = _capacity;
		else if (_size + count <= _capacity * 2)
			new_capacity = _capacity * 2;
		else
			new_capacity = _size + count;
		tmp = _allocator.allocate(new_capacity);
		unsigned int index = pos - this->begin();
		while (i < index) {
			try {
				_allocator.construct(tmp + i, *(_array + i));
			}
			catch (...) {
				for (size_t j = 0; j < i; ++j)
					_allocator.destroy(tmp + j);
				_allocator.deallocate(tmp, new_capacity);
				throw;
			}
			++i;
		}
		while (tmp_count != count) {
			try {
				_allocator.construct(tmp + index, *(first + tmp_count));
			}
			catch (...) {
				for (size_t j = 0; j < index; ++j)
					_allocator.destroy(tmp + j);
				_allocator.deallocate(tmp, new_capacity);
				throw;
			}
			++index;
			++tmp_count;
		}
		while (i < this->size()) {
			try {
				_allocator.construct(tmp + index, *(_array + i));
			}
			catch (...) {
				for (size_t j = 0; j < index; ++j)
					_allocator.destroy(tmp + j);
				_allocator.deallocate(tmp, new_capacity);
				throw;
			}
			++index;
			++i;
		}
		for (size_t i = 0; i < _size; ++i)
			_allocator.destroy(_array + i);
		_allocator.deallocate(_array, _capacity);
		_capacity = new_capacity;
		_size = _size + count;
		_array = tmp;
	}

	iterator erase(iterator pos) {
		for (size_t i = pos - this->begin(); i < _size - 1; ++i) {
			try {
				_allocator.destroy(_array + i);
				_allocator.construct(_array + i, *(_array + i + 1));
			}
			catch(...) {
				std::cout << "LOL\n";
				for (size_t j = pos - this->begin(); j < i; ++j)
					_allocator.destroy(_array + j);
				throw;
			}			
		}
		--_size;
		return &(*pos);
	}

	iterator erase(iterator first, iterator last) {
		size_type count = last - first;
		for (size_t i = first - this->begin(); i < last - this->begin(); ++i) {
			_allocator.destroy(_array + i);
		}
		for (size_t i = last - this->begin(); i < this->size(); ++ i) {
			try {
				_allocator.construct(_array + i - count, *(_array + i));
			}
			catch (...) {
				for (size_t j = last - this->begin(); j < i; ++j)
					_allocator.destroy(_array + j);
				throw;
			}
		}
		_size -= count;
		return first;
	}

	void push_back(const value_type& value) {
		if (_size == _capacity) {
			if (_size == 0)	reserve(1);
			else reserve(_capacity * 2);
		}
		_allocator.construct(_array + _size, value);
		++_size;		
	}

	void pop_back() {
		if (_size == 0) return;
		_allocator.destroy(_array + _size - 1);
		--_size;
	}

	void resize(size_type count, value_type value = value_type()) {
		if (count > _size) {
			if (count > _capacity)
				reserve(_capacity * 2);
			for (size_t i = _size; i < count; ++i) {
				try {
					_allocator.construct(_array + i, value);
				}
				catch (...) {
					for (size_t j = _size; j < i; ++j)
						_allocator.destroy(_array + j);
					throw;
				}
			}
		}
		else if (count < _size) {
			for (size_t i = count; i < _size; ++i)
				_allocator.destroy(_array + i);
		}
		_size = count;
	}

	void swap(vector& other) {
		std::swap(_array, other._array);
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
		std::swap(_allocator, other._allocator);
	}

	/*********************************************/
	/*********** Non-Member functions ************/
	/*********************************************/

	friend bool operator==(const vector& lhs, const vector& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	friend bool operator!=(const vector& lhs, const vector& rhs) { return !(lhs == rhs); }
	friend bool operator<(const vector& lhs, const vector& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	friend bool operator>(const vector& lhs, const vector& rhs) { return rhs < lhs; }
	friend bool operator<=(const vector& lhs, const vector& rhs) { return !(rhs < lhs); }
	friend bool operator>=(const vector& lhs, const vector& rhs) { return !(lhs < rhs); }

};


} // namespace ft 

#endif
