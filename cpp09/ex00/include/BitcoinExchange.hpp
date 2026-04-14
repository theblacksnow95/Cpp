#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include "colors.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <iomanip>
# include <algorithm>
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

		void	fillMap();
		void	parseInput(std::string inputFile);
		void	findExchange(std::string str);
};


#endif
