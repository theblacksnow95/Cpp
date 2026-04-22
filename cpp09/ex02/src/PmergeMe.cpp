#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other): _v1(other._v1)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	
	if (this != &other)
	{
		
	}
	std::cout << "PmergeMe Copy assignment opreator called" << std::endl;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe Destructor called." << std::endl;
}
