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


bool	check_date(std::string str)
{
	std::string res;
	std::stringstream ss;
	unsigned int val;
	unsigned int year;
	unsigned int month;
	unsigned int day;
	int	pos = str.find('-');
	int pos2 = str.find('-', pos);
	ss << str.substr(0, pos);
	ss >> year;
	if (year <= 2000 || year >= 2030)
		return (false);
	ss << str.substr(pos + 1, 2);
	ss >> month;
	if (month < 1 || month > 12)
		return (false);
	ss << str.substr(pos2);
	ss >> day;
	if (day < 1 || day > 31)
		return (false);
	return true;
}

bool	basicCheck(std::string line)
{
	if (line.find_first_not_of("1234567890|- ") == line.npos)
	{
		std::cout << RED << "Error: incorrect line input ==> " << line << RST << std::endl;
		return (false);
	}
	if (std::count(line.begin(),line.end(), ' ') != 2)
	{	
		std::cout << RED << "Error: bad input, spaces ==> " << line << RST << std::endl;
		return (false);
	}
	if (line.size() < 14)
	{
		std::cout << RED << "Error: bad input, line too short ==> " << line << RST << std::endl;
		return (false);
	}
}

bool valueCheck(std::string str)
{
	std::stringstream ss;
	unsigned int val;
	ss << str;
	ss >> val;
	if (val < 1 || val > 1000)
	{	
		if (val < 1)
			std::cout << RED << "Error: negative number" << str << RST << std::endl;
		if (val > 1000)
			std::cout << RED << "Error: not a positive number"<< str << RST << std::endl;
		return (false);
	}
}

void	BitcoinExchange::findExchange(std::string str)
{
	std::string date(str.substr(0, 10));
	std::stringstream ss(str.substr(str.find('|') + 1));
	unsigned int	val;
	ss >> val;
	std::map<std::string, float>::iterator it = _map.find(date);
	while (it == _map.end())
	{
		int day;
		int pos = date.find('-') + 1;
		ss << date.substr(pos, 2);
		ss >> day;
		if (day > 0 && day <= 31)
		{
			day--;
			ss << day;
			date.replace(pos, 2, ss.str());
		}
	}
	
}

void	BitcoinExchange::parseInput(std::string inputFile)
{
	std::ifstream	inFile;
	std::string		line;
	inFile.open(inputFile.c_str());
	if (!inFile) 
	{
		std::cout << YLL << "Error: cannot open file, file may lack permissions or may not exist." << RST << std::endl;
		return ;
	}
	getline(inFile, line);
	while (getline(inFile, line))
	{
		std::string date(line.substr(0, line.find(' ')));
		std::string value(line.substr(line.find('|') + 1));
		if (!basicCheck(line) || !check_date(date) || ! valueCheck(value))
		{
			std::cout << RED << "incorrect line" << RST << std::endl;
			break;
		}
		else
		{
			findExchange(line);
		}

	}
}

void	BitcoinExchange::fillMap()
{
	std::ifstream	infile;
	infile.open("data.csv"); // cuidado con donde esta data guardado
	if (!infile)
		return ;
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
	std::cout << GRN << "Data filled correctly from data.csv" << RST << std::endl;
}
