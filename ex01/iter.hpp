#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename Addr, typename Func>
void iter(Addr *arr, size_t size, Func f)
{
	if (!arr)
		return;
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

#endif
