#include "Array.hpp"

template<typename T>
Array<T>::Array(): _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array<T>& other): _array(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
	std::cout << "Array Copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		_array = new T[other._size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	std::cout << "Array Copy assignment opreator called" << std::endl;
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
T&		Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw Array<T>::ExcOOBounds();
	else
		return (_array[i]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw (ExcOOBounds());
	else
		return (_array[i]);
}

template <typename T>
const char* Array<T>::ExcOOBounds::what() const throw()
{
	return EXCOOBOUNDS;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
