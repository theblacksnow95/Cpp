#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include "colors.hpp"
# include <algorithm>
# include <vector>
# include <deque>
# include <list>
# include "easyfind.tpp"
# define ERRORFIND	"Value not present in the secuence, try with another."


template <typename T>
void	easyfind(const T &cont, int target);

class EValueNotFound: public std::exception
{
	public:
		const char *what() const throw()
		{
			return ERRORFIND;
		}
};


#endif
