#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	if (ac <= 2 || ac > 3001) return(std::cout << RED << "Error: incorrect args" << RST << std::endl, 1);
	PmergeMe m(ac - 1, ++av);
	return (0);
}
