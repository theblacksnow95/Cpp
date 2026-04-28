#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	if (ac <= 2) return(std::cout << RED << "Error: incorrect args" << RST << std::endl, 1);
	PmergeMe m(ac - 1, ++av);
	m.sortvect();
	m.sortdeque();
	return (0);
}
