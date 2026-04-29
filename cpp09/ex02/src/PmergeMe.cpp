#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

bool	checkDigits(char *str);

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int ac, char** av)
{
	//std::cout << GRN << "Size of sequence ==> " << ac << RST << std::endl;
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
	_check = _v1;
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
	//std::cout << "PmergeMe Destructor called." << std::endl;
}

bool	checkDigits(char *str)
{
	std::string num(str);
	if (num.find_first_not_of("01234556789 ") != num.npos)
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
	if (!isOrdered(_v1)){
		std::cout << "Original sequence: " << _v1 << std::endl << std::endl;
		std::clock_t start, end;
		start = std::clock();
		std::vector<int> sorted = _mergeSort(_v1);
		end = std::clock();
		printlists(sorted);
		std::sort(_check.begin(), _check.end());
		printlists(_check);
	std::cout << GRN << "Time taken by vector: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms" << RST << std::endl;
	}
}

void	PmergeMe::sortdeque()
{
	if (!isOrdered(_v1)) {
		std::clock_t start, end;
		std::deque<int> d(_v1.begin(), _v1.end());
		start = std::clock();
		std::deque<int> sorted = _mergeSort(d);
		end = std::clock();
		printlists(sorted);
		std::sort(_check.begin(), _check.end());
		printlists(_check); 
		std::cout << GRN << "Time taken by deque: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms" << RST << std::endl;
	}
}


// void	PmergeMe::addIndex(std::vector<size_t>& vct)
// {
// 	if ( vct.size() <= 2)
// 		return ;
// 	size_t count = 0;
// 	for (size_t i = 1; i < vct.size() ; ++i)
// 	{
// 		size_t prev = vct[i - 1 - count];
// 		size_t curr = vct[i];
// 		size_t diff = curr - prev;
// 		count = 0;
// 		if (prev > curr)
// 			diff = 0;
// 		// std::cout << YLL << "Values prev, curr: " << prev << ", " << curr << " diff ==> "<< diff << RST << std::endl;
// 		if (diff > 1) {
// 			size_t inter = curr - 1;
// 			// std::cout << GRN << "\tNumber = " << inter << RST << std::endl;
// 			while (inter > prev)
// 			{
// 				vct.insert(vct.begin() + i + 1, inter);
// 				// std::cout << BLE << "\tval inserted " << inter << RST << std::endl;
// 				inter--;
// 				i++;
// 				count++;
// 			}
// 			// std::cout << RED << "\tcount: " << count << RST << std::endl;
// 		}
// 	}
// 	size_t max = findBiggest(vct);
// 	size_t target = _v1.size();
// 	// std::cout << YLL << "Max:" << max << RST << std::endl;
// 	while (max < target)
// 	{
// 		// std::cout << YLL << "Adding remaining indexes:" << target << RST << std::endl;
// 		vct.push_back(target--);
// 	}
// 	vct.erase(vct.begin());
// }

// void	PmergeMe::_createSequenceJB()
// {
// 	size_t	size = (_v1.size());
// 	_seqJcb.push_back(0);
// 	_seqJcb.push_back(1);
// 	for (size_t i = 2; i < _v1.size(); i++) {
// 		size_t val = _seqJcb[i - 1] + 2 * _seqJcb[i - 2];
// 		if (val > size)
// 			break;
// 		_seqJcb.push_back(val);
// 		// std::cout << GRN << "value pushed sequence: " << val << RST << std::endl;
// 	}
// 	// std::cout << GRN << "Jacobsthal sequence complete: " << RST << std::endl;
// 	addIndex(_seqJcb);
// 	printlists(_seqJcb);
// }




std::ostream&	operator<<(std::ostream& o, const std::vector<int>& obj)
{
	for (std::vector<int>::const_iterator it = obj.begin(); it != obj.end(); ++it)
	{
		o << YLL << *it;
		if (it + 1 != obj.end())
			o << " ";
	}
	return o;
}


std::ostream&	operator<<(std::ostream& o, const std::deque<int>& obj)
{
		for (std::deque<int>::const_iterator it = obj.begin(); it != obj.end(); ++it)
	{
		o << YLL << *it;
		if (it + 1 != obj.end())
			o << " ";
	}
	return o;
}
