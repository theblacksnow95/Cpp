#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	_map = other._map;
	std::cout << "BitcoinExchange Copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	
	if (this != &other)
	{
		_map = other._map;
	}
	std::cout << "BitcoinExchange Copy assignment opreator called" << std::endl;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange Destructor called." << std::endl;
}


int	BitcoinExchange::fillMap(std::string dataFile)
{
	std::ifstream	infile;
	infile.open(dataFile.c_str());
	if (!infile)
		return (1);
	std::string line;
	std::string date;
	std::string value;
	while (getline(infile, line))
	{
		int pos = line.find(',');
		date = line.substr(0, pos);
		value = line.substr(pos + 1);
		_map[date] = atof(value.c_str());
	}
	int j = 0;
	for (std::map<std::string, float>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		std::cout << GRN << "map->date:\t" << it->first << "\t\tvalue->:\t" << it->second << RST << std::endl;
		j++;
	}
	std::cout << YLL << "Count = " << j << RST << std::endl;
	return (0);
}
