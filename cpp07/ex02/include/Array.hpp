#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include "colors.hpp"

# define	EXCOOBOUNDS "Incorrect size: out of bounds."

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

	//operator overloads for (=,[], const[])
	Array&		operator=(const Array<T>& other);
	T&			operator[](unsigned int i);
	const T&	operator[](unsigned int i) const;

	// member func returns size of the arr.
	unsigned int size() const;

	// exception out of bounds
	class ExcOOBounds: public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif
