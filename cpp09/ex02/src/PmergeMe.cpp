#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

bool	checkDigits(char *str);

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int ac, char** av)
{
	//std::cout << GRN << "Size of sequence ==> " << ac << RST << std::endl;
	for (int i = 0; i < ac; i++) {
		if (!checkDigits(av[i])   ) {
			std::cout << RED << "Error: incorrect arguments " << RST << std::endl;
			return ;
		}
	}
	for (int i = 0; i < ac; i++) {
		_v1.push_back(std::strtod(av[i], NULL));
		// std::cout << YLL << "num: " << _v1[i] << RST << std::endl;
	}
	_check = _v1;
	if (!isOrdered(_v1)) {
		sortvect();
		sortdeque();
		timeDuration();
	}
	else
		std::cout << RED << "Error: invalid sequence, must be positive and not sorted" << RST << std::endl;
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
	//std::cout << "PmergeMe Destructor called." << std::endl;
}

bool	checkDigits(char *str)
{
	std::string num(str);
	if (num.find_first_not_of("01234556789") != num.npos)
		return (false);
	if (std::strtod(str, NULL) > __INT_MAX__ || std::strtod(str , NULL) < 0)
		return (false);
	return (true);
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

void	PmergeMe::sortvect()
{
	if (!isOrdered(_v1)) {
		std::cout << "Original sequence: " << _v1 << std::endl << std::endl;
		std::clock_t start, end;
		start = std::clock();
		std::vector<int> sorted = _mergeSort(_v1);
		end = std::clock();
		std::cout << GRN << "Vector result: " << RST << std::endl;
		std::cout << YLL << sorted << RST << std::endl;
		std::sort(_check.begin(), _check.end());
		if (!isOrdered(sorted))
			std::cout << RED << "Error sorting the sequence" << RST << std::endl;
		_timeVect = 1000.0 * (end - start) /  CLOCKS_PER_SEC;
	}
}

void	PmergeMe::sortdeque()
{
	if (!isOrdered(_v1)) {
		std::clock_t start, end;
		std::deque<int> d(_v1.begin(), _v1.end());
		start = std::clock();
		std::deque<int> sorted = _mergeSort(d);
		std::cout << GRN << "Deque result: " << RST << std::endl;
		std::cout << YLL << sorted << RST << std::endl;
		end = std::clock();
		if (!isOrdered(sorted))
			std::cout << RED << "Error sorting the sequence" << RST << std::endl;
		_timeDeque = 1000.0 * (end - start) /  CLOCKS_PER_SEC;
	}
}

void	PmergeMe::timeDuration()
{
	std::cout << GRN << "Time taken by vector of size " << _v1.size() << " ==>\t" << _timeVect << "ms" << RST << std::endl;
	std::cout << GRN << "Time taken by deque of size  " << _v1.size() << " ==>\t" << _timeDeque << "ms" << RST << std::endl;

}


std::ostream&	operator<<(std::ostream& o, const std::vector<int>& obj)
{
	for (std::vector<int>::const_iterator it = obj.begin(); it != obj.end(); ++it)
	{
		o  << *it;
		if (it + 1 != obj.end())
			o << " ";
	}
	return o;
}


std::ostream&	operator<<(std::ostream& o, const std::deque<int>& obj)
{
		for (std::deque<int>::const_iterator it = obj.begin(); it != obj.end(); ++it)
	{
		o << *it;
		if (it + 1 != obj.end())
			o << " ";
	}
	return o;
}
