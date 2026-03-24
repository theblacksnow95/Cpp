#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include <algorithm>
# include <stack>

template <typename T, class container=std::deque<T>>
class MutantStack: public std::stack<T>
{

	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& other);
		~MutantStack();

		typedef typename container::iterator iterators;
		iterators begin();
};


#endif
