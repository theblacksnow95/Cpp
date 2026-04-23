#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include "colors.hpp"
# include <iostream>
# include <utility>
# include <string>
# include <vector>
# include <cstdlib>
# include <climits>

class PmergeMe
{
	private:
		std::vector<int> _v1;
		std::vector<std::vector<int>::iterator> its;
		void	fillVector(int *arr);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
		void	sortof(char** args, int size);
};

#endif
