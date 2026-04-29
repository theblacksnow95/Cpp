#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include "colors.hpp"
# include <iostream>
# include <utility>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <climits>
# include <algorithm>
# include <ctime>

class PmergeMe
{
	private:
		template <typename T>
		void									_swapFill(T& a, T& b, T& vct);
		template <typename T>
		T										_mergeSort(T& vect);
		template <typename T>
		void									_insertPend(T& main, T& pend, std::vector<size_t> order, T copy_a);
		std::vector<int>						_v1;
		std::vector<int>						_check;
		std::vector<size_t >					_seqJcb;
		std::vector<size_t>						_createJCB(size_t n);
		// void									_fillVector(int *arr);
		// void									_createSequenceJB();
		// void									addIndex(std::vector<size_t>& vct);
		public:
		PmergeMe();
		PmergeMe(int ac, char** av);
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
		void	sortvect();
		void	sortdeque();
};


std::ostream&	operator<<(std::ostream& o, const std::vector<int>& obj);
std::ostream&	operator<<(std::ostream& o, const std::deque<int>& obj);

#endif
