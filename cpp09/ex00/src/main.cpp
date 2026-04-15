#include "BitcoinExchange.hpp"

int	main(int ac, char** av)
{
	if (ac != 2) return(std::cout << RED << "Error: incorrect arguments" << RST << std::endl, 1);

	BitcoinExchange btc;

	btc.parseInput(av[1]);
	
	return (0);
}
