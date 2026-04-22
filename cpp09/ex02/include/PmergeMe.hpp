#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include "colors.hpp"
# include <iostream>
# include <utility>
# include <string>
# include <vector>
# include <cstdlib>

class PmergeMe
{
	private:
		std::vector<std::pair<int, int> > _v1;
		void	fillVector(int *arr);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
		void	sortof(char** args, int size);
};

#endif
