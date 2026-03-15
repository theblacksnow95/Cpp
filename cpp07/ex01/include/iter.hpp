#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <colors.hpp>


template <typename T1, typename F>

void	iter(T1 *array, size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif
