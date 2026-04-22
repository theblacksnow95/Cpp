#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include <utility>
# include <vector>

class PmergeMe
{
	private:
		vector<int> _v1;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
};


#endif
