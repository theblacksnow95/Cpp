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


std::string	check_date(std::string str)
{
	std::string year;
	std::string month;
	std::string day;
	std::string res;

	if (str.length() != 10 || str.find_first_not_of("0123456789-"))
	{
		std::cout << RED << "Error incorrect format" << RST << std::endl;
		return NULL;
	}
	int	pos = str.find('-');
	int pos2 = str.find('-', pos);
	year = str.substr(0, pos);
	month = str.substr(pos + 1, 2);
	day = str.substr(pos2);
	res.append(year + '-' + month + '-' + day);
	return res;
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
	getline(infile, line);
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
		std::cout <<  std::fixed << std::setprecision(2) << GRN << "map->date:\t" << it->first << "\t\tvalue->:\t" << it->second << RST << std::endl;
		j++;
	}
	std::cout << YLL << "Count = " << j << RST << std::endl;
	return (0);
}
