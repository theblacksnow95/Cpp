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
		std::vector<int>						_v1;
		void									_fillVector(int *arr);
		void									_swapFill(std::vector<int>& a, std::vector<int>& b, std::vector<int>& vct);
		std::vector<int>						_mergeSort(std::vector<int>& vect);
		std::vector<size_t >						_seqJcb;
		void									_createSequenceJB();
	public:
		PmergeMe();
		PmergeMe(int ac, char** av);
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
		void	sortvect();
};

#endif
