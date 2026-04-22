#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	if (ac <= 2) return(std::cout << RED << "Error: incorrect args" << RST << std::endl, 1);
	PmergeMe m;
	m.sortof(++av, ac - 1);
	return (0);
}
