#include "PmergeMe.hpp"

bool	checkDigits(char *str);

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int ac, char** av)
{
	std::cout << GRN << "Size of sequence ==> " << ac << RST << std::endl;
	for (int i = 1; i < ac; i++) {
		if (!checkDigits(av[i])) {
			std::cout << RED << "Error: incorrect arguments " << RST << std::endl;
			return ;
		}
	}
	for (int i = 0; i < ac; i++) {
		_v1.push_back(std::strtod(av[i], NULL));
		// std::cout << YLL << "num: " << _v1[i] << RST << std::endl;
	}
	// _createSequenceJB();
}

PmergeMe::PmergeMe(const PmergeMe& other): _v1(other._v1)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	
	if (this != &other)
	{
		_v1 = other._v1;
	}
	std::cout << "PmergeMe Copy assignment opreator called" << std::endl;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe Destructor called." << std::endl;
}

bool	checkDigits(char *str)
{
	std::string num(str);
	if (num.find_first_not_of("01234556789 ") != num.npos)
		return (false);
	if (std::strtod(str, NULL) > INT_MAX || std::strtod(str , NULL) < 0)
		return (false);
	return (true);
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
	
	for (typename T::iterator it = vect.begin(); it < vect.end(); it++)
	{
		std::cout << YLL << *it << " " << RST;
	}
	std::cout << std::endl;
}

void	PmergeMe::_swapFill(std::vector<int>& a, std::vector<int>& b, std::vector<int>& vct)
{
	for (std::vector<int>::iterator it = vct.begin(); it + 1 != vct.end() && it != vct.end(); it+=2) {
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

void	PmergeMe::_insertPend(std::vector<int>& main, std::vector<int>& pend, std::vector<size_t> order, std::vector<int> copy_a)
{
	for (size_t i = 0; i < order.size(); ++i) {
		size_t idx = order[i];
		if (idx >= pend.size())
			continue;
		int value = pend[idx];
		size_t real_id = idx;
		if (real_id < copy_a.size())
			real_id = copy_a[idx];
		else
			real_id = __INT_MAX__;
		std::vector<int>::iterator bound = std::find(main.begin(), main.end(), real_id);

		if (bound == main.end())
			bound = main.end();
		
		std::vector<int>::iterator pos = std::upper_bound(main.begin(), bound, value);
		main.insert(pos, value);
	}
}

std::vector<int>	PmergeMe::_mergeSort(std::vector<int>& vect)
{
	if (vect.size() <= 1)
		return vect;
	std::vector<int> a, b, copy_vect(vect);
	_swapFill(a, b, copy_vect);
	a = _mergeSort(a);
	std::vector<int> copy_a = a;
	std::vector<size_t> order = _createJCB(b.size());
	_insertPend(a, b, order, copy_a);
	return a;
}

void	PmergeMe::sortvect()
{
	// printVector(_v1);
	std::vector<int> sorted = _mergeSort(_v1);
	std::cout << BLE << "Original secuence:" << RST << std::endl;
	printlists(_v1);
	std::cout << YLL << "Modified list" << RST << std::endl;
	printlists(sorted);
	std::cout << BLE << "Comparing with sort function" << RST << std::endl;
	std::sort(_v1.begin(), _v1.end());
	printlists(_v1);
}

std::vector<size_t> PmergeMe::_createJCB(size_t n)
{
	std::vector<size_t> order;

	if (n == 0)
		return order;
	order.push_back(0);
	size_t j_prev = 1;
	size_t j_curr = 3;
	while (order.size() < n)
	{
		size_t limit = (j_curr < n) ? j_curr : n;
		for (size_t k = limit; k > j_prev && order.size() < n; --k) {
			order.push_back(k - 1);
		}
		size_t tmp = j_curr;
		j_curr = j_curr + 2 * j_prev;
		j_prev = tmp;
	}
	return (order);
}

size_t	findBiggest(std::vector<size_t> vct)
{
	size_t max = 0;
	for (std::vector<size_t>::iterator it = vct.begin(); it < vct.end(); it++)
	{
		if (*it > max)
			max  = *it;
	}
	return (max);
}

void	PmergeMe::addIndex(std::vector<size_t>& vct)
{
	if ( vct.size() <= 2)
		return ;
	size_t count = 0;
	for (size_t i = 1; i < vct.size() ; ++i)
	{
		size_t prev = vct[i - 1 - count];
		size_t curr = vct[i];
		size_t diff = curr - prev;
		count = 0;
		if (prev > curr)
			diff = 0;
		// std::cout << YLL << "Values prev, curr: " << prev << ", " << curr << " diff ==> "<< diff << RST << std::endl;
		if (diff > 1) {
			size_t inter = curr - 1;
			// std::cout << GRN << "\tNumber = " << inter << RST << std::endl;
			while (inter > prev)
			{
				vct.insert(vct.begin() + i + 1, inter);
				// std::cout << BLE << "\tval inserted " << inter << RST << std::endl;
				inter--;
				i++;
				count++;
			}
			// std::cout << RED << "\tcount: " << count << RST << std::endl;
		}
	}
	size_t max = findBiggest(vct);
	size_t target = _v1.size();
	// std::cout << YLL << "Max:" << max << RST << std::endl;
	while (max < target)
	{
		// std::cout << YLL << "Adding remaining indexes:" << target << RST << std::endl;
		vct.push_back(target--);
	}
	vct.erase(vct.begin());
}

void	PmergeMe::_createSequenceJB()
{
	size_t	size = (_v1.size());
	_seqJcb.push_back(0);
	_seqJcb.push_back(1);
	for (size_t i = 2; i < _v1.size(); i++) {
		size_t val = _seqJcb[i - 1] + 2 * _seqJcb[i - 2];
		if (val > size)
			break;
		_seqJcb.push_back(val);
		// std::cout << GRN << "value pushed sequence: " << val << RST << std::endl;
	}
	// std::cout << GRN << "Jacobsthal sequence complete: " << RST << std::endl;
	addIndex(_seqJcb);
	printlists(_seqJcb);
}
