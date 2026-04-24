#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
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
	printlists(a);
	printlists(b);
	
	return a;
}

void	PmergeMe::sortvect(char** args, int size)
{
	for (int i = 1; i < size; i++) {
		if (!checkDigits(args[i])) {
			std::cout << RED << "Error: incorrect arguments " << RST << std::endl;
			return ;
		}
	}
	for (int i = 0; i < size; i++) {
		_v1.push_back(std::strtod(args[i], NULL));
		// std::cout << YLL << "num: " << _v1[i] << RST << std::endl;
	}
	// sortBigVect(_v1);
	printVector(_v1);
	_mergeSort(_v1);
	std::cout << YLL << "Size: " << size << RST << std::endl;
}


void	PmergeMe::_createSequenceJB()
{
	for (size_t i = 0; i < _v1.size(); i++)
}
