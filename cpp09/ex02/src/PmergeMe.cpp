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
	_createSequenceJB();
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

void	printVector(std::vector<int > vect)
{
	std::cout << BLE << "Printing pairs & leftover: " << RST << std::endl;
	for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it+=2) {
		if (it + 1 == vect.end() ) {
			std::cout << BLE << "leftover ==> " << *(it) << RST << std::endl;
			break;
		}
		// std::cout << YLL << "val: " << *it << RST << std::endl;
		std::cout << BLE << "[a = " << *it << ", b = " << *(it + 1)  << "]" << RST << std::endl;
	}
}

void	printlists(std::vector<int> vect)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << YLL <<  vect[i] << " " << RST;
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

std::vector<int>	PmergeMe::_mergeSort(std::vector<int>& vect)
{
	if (vect.size() <= 1)
		return vect;
	std::vector<int> a, b, copy_vect(vect);
	_swapFill(a, b, copy_vect);
	a = _mergeSort(a);
	// printlists(a);
	// printlists(b);
	
	return a;
}

void	PmergeMe::sortvect()
{
	// printVector(_v1);
	_mergeSort(_v1);
}

void	addIndex(std::vector<size_t>& vct)
{
	size_t count = 0;
	for (size_t i = 1; i < vct.size() ; ++i)
	{
		size_t prev = vct[i  - 1];
		if (count > 1)
			prev = vct[i - count];
		size_t curr = vct[i];
		size_t diff = curr - prev;
		if (prev > curr)
			diff = 0;
		std::cout << YLL << "Values prev, curr: " << prev << ", " << curr << " diff ==> "<< diff<< RST << std::endl;
		if (diff > 1) {
			size_t inter = curr - 1;
			std::cout << YLL << "Number = " << inter << RST << std::endl;
			while (inter > prev)
			{
				vct.insert(vct.begin() + i + 1, inter);
				std::cout << BLE << "\tval inserted " << inter << RST << std::endl;
				inter--;
				i++;
				count++;
			}
		}
	}
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
		std::cout << GRN << "value pushed sequence: " << val << RST << std::endl;
	}
	std::cout << GRN << "Jacobsthal sequence complete: " << RST << std::endl;
	addIndex(_seqJcb);
	for (size_t i = 0; i < _seqJcb.size(); i++) {
		std::cout << YLL << _seqJcb[i] << " " << RST;
	}
	std::cout << std::endl;
}
