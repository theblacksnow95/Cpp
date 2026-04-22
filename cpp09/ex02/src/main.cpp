#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	if (ac != 2) return(std::cout << RED << "Error: args ==> " << YLL << "./RPN '7 7 * 7 -'" << RST << std::endl, 1);
	try
	{
		vector<int> v1;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << '\n';
	}
	return (0);
}
