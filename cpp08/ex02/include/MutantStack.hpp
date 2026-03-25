#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include <algorithm>
# include <stack>


/**
 *
 * @brief Class MutantStack is wrapper of the class **stack**, with custom iterators. Inherits std::stack<T>
 *
 * @details
 * Stack is a container adaptor, it basically uses another container to store
 * it's data, by default std::deque<T>
 *
 * From the std::stack<T> we use the member object std::deque<T> to have
 * access to the iterators from the deque class inside the stacj.
 *
 * We have to redifine a new data type iterator, using 'typedef typename'
 * To access the type, we access the member type of the stack class
 * by using ::container_type then we access the iterator
 * we nneed to use ::iterator, ::const_iterator, etc
 *
 *
*/
template <typename T>
class MutantStack: public std::stack<T>
{

	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator			iterator;
		typedef typename std::stack<T>::container_type::const_iterator		const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const ;

		reverse_iterator rbegin();
		reverse_iterator rend();
};


#endif
