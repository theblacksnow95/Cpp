#include "PmergeMe.hpp"

template <typename T>
bool	isOrdered(T& seq)
{
	bool sorted = std::adjacent_find(seq.begin(), seq.end(), std::greater<int>()) == seq.end();

	if (sorted)
		return (true);
	else
		return (false);
}


template <typename T>
void	printVector(T vect)
{
	std::cout << BLE << "Printing pairs & leftover: " << RST << std::endl;
	for (typename T::iterator it = vect.begin(); it < vect.end(); it+=2) {
		if (it + 1 == vect.end() ) {
			std::cout << BLE << "leftover ==> " << *(it) << RST << std::endl;
			break;
		}
		// std::cout << YLL << "val: " << *it << RST << std::endl;
		std::cout << BLE << "[a = " << *it << ", b = " << *(it + 1)  << "]" << RST << std::endl;
	}
}
template <typename T>
void	printlists(T vect)
{

	for (typename T::iterator it = vect.begin(); it != vect.end(); ++it)
	{
		std::cout << YLL << *it;
		if (it + 1 != vect.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}
template <typename T>
void	PmergeMe::_swapFill(T& a, T& b, T& vct)
{
	for (typename T::iterator it = vct.begin(); it + 1 != vct.end() && it != vct.end(); it+=2) {
		if (*it > *(it + 1)) {
			a.push_back(*it);
			b.push_back(*(it + 1));
		}
		else {
			a.push_back(*(it + 1));
			b.push_back(*it);
		}
		if (it + 1 == vct.end())
			break;
	}
	if (vct.size() % 2 != 0) {
		b.push_back(vct.back());
	}
}
template <typename T>
void	PmergeMe::_insertPend(T& main, T& pend, std::vector<size_t> order, T copy_a)
{
	for (size_t i = 0; i < order.size(); ++i) {
		size_t idx = order[i];
		if (idx >= pend.size())
			continue;
		int value = pend[idx];
		typename T::iterator bound = main.end();
		if (idx < copy_a.size())
		{
			int anchor = copy_a[idx];
			for (typename T::iterator it = main.begin(); it < main.end(); ++it) {
				if (*it == anchor){
					bound = it;
					break;
				}
			}
		}
		if (bound == main.end())
			bound = main.end();

		typename T::iterator pos = std::upper_bound(main.begin(), bound, value);
		//std::cout << RED << "Valor insertado ==>" << value << RST << std::endl;
		main.insert(pos, value);
	}
}
template <typename T>
T	PmergeMe::_mergeSort(T& sec)
{
	if (sec.size() <= 1)
		return sec;
	T a, b, copy_vect(sec);
	_swapFill(a, b, copy_vect);
	T copy_a = a;
	a = _mergeSort(a);
	std::vector<size_t> order = _createJCB(b.size());
	_insertPend(a, b, order, copy_a);
	return a;
}
