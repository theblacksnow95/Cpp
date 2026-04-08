#include "BitcoinExchange.hpp"

int	main(int ac, char** av)
{
	if (ac != 2) return(std::cout << RED << "Error: incorrect arguments" << RST << std::endl, 1);

	BitcoinExchange btc;
	std::ifstream	inFile;
	std::string		line;
	// inFile.open(av[1]);
	// if (!inFile) 
	// {
	// 	std::cout << YLL << "Error: cannot open file, file may lack permissions or may not exist." << RST << std::endl;
	// 	return (std::strerror(errno), 1);
	// }
	// while (getline(inFile, line))
	// {
	// 	std::cout << GRN << line << RST << std::endl;
	// }
	btc.fillMap(av[1]);
	return (0);
}
