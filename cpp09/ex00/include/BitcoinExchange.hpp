#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include "colors.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <iomanip>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _map;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		int	fillMap(std::string dataFile);
};


#endif
