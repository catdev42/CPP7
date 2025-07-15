#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// Overload for non-const arrays
template <typename T, typename F>
void iter(T *arr, size_t size, F f)
{
	if (!arr)
		return;
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}
// void(f*)(T)

template <typename T, typename F>
void iter(const T *arr, size_t size, F f)
{
	if (!arr)
		return;
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}



#endif
