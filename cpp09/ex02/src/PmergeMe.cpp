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
	return (true);
}

void	printVector(std::vector<std::pair<int, int> > vect)
{
	std::vector<std::pair<int, int> >::iterator it = vect.begin();
	while (it != vect.end())
	{
		std::cout << BLE << "pair [a = " << it->first << ", b = " << it->second << "]" << RST << std::endl;
		it++;
	}
}

void	sortLargerVect(std::vector<std::pair<int, int> > vect)
{
	std::vector<std::pair<int, int> >::iterator it = vect.begin();
	if (it->second > it->first)
	{
		
	}
	
}

void	PmergeMe::sortof(char** args, int size)
{
	for (int i = 0; i < size; i++) {
		if (!checkDigits(args[i])) {
			std::cout << RED << "Error: incorrect arguments " << RST << std::endl;
			return ;
		}
	}
	int	arr[size];
	for (int i = 0; i < size; i++) {
		arr[i] = atoi(args[i]);
		std::cout << YLL << "num: " << arr[i] << RST << std::endl;
	}
	int leftover = -1;
	for (int i = 0; i < size; i++) {
		_v1.push_back(std::pair<int, int>(arr[i], arr[i + 1]));
		i++;
		if (i == size - 2  && size % 2 != 0) {
			leftover = arr[i + 1];
			break ;}
	}
	std::cout << YLL << "Size: " << size << RST << std::endl;
	std::cout << YLL << "Leftover value: " << leftover << RST << std::endl;
	printVector(_v1);
}
