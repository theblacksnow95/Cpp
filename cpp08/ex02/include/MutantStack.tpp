#include "MutantStack.hpp"

template<typename T, class container>
MutantStack<T, container>::MutantStack()
{}

template<typename T, class container>
MutantStack<T, container>::MutantStack(const MutantStack<T, container>& other)
{
	*this = other;
}
template<typename T, class container>
MutantStack<T, class container>::~MutantStack()
{}

template<typename T, class container>
typedef typename container::iterator iterators;
iterators MutantStack::begin()
{

}
