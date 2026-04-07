#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{
	private:
		std::string	val;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();
};


#endif
