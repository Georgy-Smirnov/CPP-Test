#ifndef _ARRAY_HPP_
# define _ARRAY_HPP_

#define INDEX 20

template <typename T>
class Array
{
public:
	unsigned int size() const { return (sizeArray); }
	Array() : sizeArray(0), array(new T()) {}
	Array(unsigned int sizeArray) : sizeArray(sizeArray), array(new T[sizeArray]) {}
	Array(const Array& tmp) : sizeArray(tmp.sizeArray), array(new T[sizeArray])
	{
		for (unsigned int i = 0; i < tmp.sizeArray; i++)
			array[i] = tmp.array[i];
	}
	Array& operator=(const Array& tmp)
	{
		if (this == &tmp)
			return (*this);
		delete (array);
		array = new T[tmp.sizeArray];
		for (unsigned int i = 0; i < tmp.sizeArray; i++)
			array[i] = tmp.array[i];
		sizeArray = tmp.sizeArray;
		return (*this);
	}
	T& operator[](const int index)
	{
		if (index >= static_cast<const int>(sizeArray) || index < 0)
			throw (OutRangeArrayExeption());
		return (array[index]);
	}
	class OutRangeArrayExeption : public std::exception
	{
		const char* what() const throw()
		{
			return ("Index out of Range array");
		}
	};
	~Array(){ delete [](array); }
private:
	unsigned int sizeArray;
	T* array;
};

#endif