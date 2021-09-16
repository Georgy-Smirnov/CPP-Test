#ifndef _ITER_HPP_
# define _ITER_HPP_

template <typename T>
void iter(T* array, int size, void(*print)(const T&))
{
	for (int i = 0; i < size; i++)
		print(array[i]);
}

#endif