#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include "colors.hpp"

template <typename T>
class Array
{
private:
	T				*_array;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array<T>& other);

	unsigned int size() const;
};

#endif
