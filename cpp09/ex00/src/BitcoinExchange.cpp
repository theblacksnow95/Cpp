#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	fillMap();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _map(other._map)
{
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
}


bool	check_date(std::string str)
{
	std::string res;
	std::stringstream ss;
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int maxday;
	int	pos = str.find('-');
	int pos2 = str.rfind('-');
	if (str.find_first_not_of("1234567890-") != str.npos)
	{
		std::cout << RED << "Error: incorrect date ==> " << str << RST << std::endl;
		return (false);
	}
	ss << str.substr(0, pos);
	ss >> year;
	if (year < 2009 || year >= 2030)
	{
		std::cout << YLL << "Error: incorrect date ==> " << str << RST << std::endl;
		return (false);
	}
	ss.clear();
	ss << str.substr(pos + 1, 2);
	ss >> month;
	if (month == 2)
		maxday = 29;
	else if (month == 4 || month == 6 || month == 8 || month == 11)
		maxday = 30;
	else
		maxday = 31;
	ss.clear();
	ss << str.substr(pos2 + 1);
	ss >> day;
	if (month < 1 || month > 12 || day < 1 || day > 31 || day > maxday)
	{
		std::cout << RED << "Error: incorrect date ==> " << str << RST << std::endl;
		return (false);
	}
	return true;
}

bool	basicCheck(std::string line)
{
	std::string s1(line.substr(0, line.find('|')));
	std::string s2(line.substr(line.find('|') + 1) );
	int neg = s2.find('-');
	if (line.empty()){
		std::cout << RED << "Error: empty line" << RST << std::endl;
		return (false);}
	if (s1.find_first_not_of("1234567890- ") != line.npos || line.find_first_not_of("1234567890-.| ") != line.npos)
	{
		std::cout << RED << "Error: incorrect line input ==> " << line << RST << std::endl;
		return (false);
	}
	if (s2[0] != ' ' || s2.find('.') != s2.rfind('.') )
	{
		std::cout << RED << "Error: incorrect line input ==> " << line << RST << std::endl;
		return (false);
	}
	if ( (neg != 1 && neg !=-1 && neg != 14) || s2.find('-') != s2.rfind('-'))
	{
		std::cout << RED << "Error: incorrect line input ==> " << line << " " << RST << std::endl;
		return (false);
	}
	if (line.size() < 14)
	{
		std::cout << RED << "Error: bad input ==> " << line << RST << std::endl;
		return (false);
	}
	if (std::count(line.begin(),line.end(), ' ') != 2)
	{	
		std::cout << RED << "Error: bad input ==> " << line << RST << std::endl;
		return (false);
	}
	return (true);
}

bool valueCheck(std::string str)
{
	std::stringstream ss(str);
	double val;
	ss >> val;
	if (val < 0 || val > 1000)
	{	
		if (val < 1)
			std::cout << RED << "Error: negative number ==> " << str << RST << std::endl;
		if (val > 1000)
			std::cout << RED << "Error: out of bounds, too big ==> "<< str  << RST << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::findExchange(std::string str)
{
	std::string date(str.substr(0, 10));
	std::stringstream ss(str.substr(str.find('|') + 1));
	double	val;
	ss >> val;
	std::map<std::string, float>::iterator it = _map.find(date);
	if (it == _map.end()){
		it = _map.lower_bound(date);
		it--;
		std::cout << GRN << std::fixed << std::setprecision(2) << date << " => " << val << " = " << val * it->second << RST << std::endl;
	}
	else
		std::cout << GRN << std::fixed << std::setprecision(2) << date << " => " << val << " = " << val * it->second << RST << std::endl;
}

bool allSpaces(std::string str)
{
	for (size_t i= 0; i < str.size();i++) 
		if (!isspace(str[i])) 
			return false;
	return true;
}

bool	checkEmptyfile(std::string input)
{
	std::ifstream inFile(input.c_str());
	std::stringstream buf;
	buf << inFile.rdbuf();
	std::string content(buf.str());
	if (content.empty()){
		std::cout << RED << "Error: empty file" << RST << std::endl;
		return (true);}
	if (allSpaces(content)){
		std::cout << RED << "Error: empty file" << RST << std::endl;
		return (true);}
	return (false);
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
	if (checkEmptyfile(inputFile))
		return ;
	getline(inFile, line);
	if (line != HEADER){
		std::cout << RED << "Error: wrong or missing header" << RST << std::endl;
		return ;}
	while (getline(inFile, line))
	{
		std::string date(line.substr(0, line.find(' ')));
		std::string value(line.substr(line.find('|') + 1));
		if (!basicCheck(line) || !check_date(date) || !valueCheck(value))
			continue ;
		else
			findExchange(line);
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
	std::cout << GRN << "Data filled correctly from data.csv" << RST << std::endl;
}



// int main() 
// {
// 	std::ifstream file("file.txt");
// 	std::stringstream buffer;
// 	buffer << file.rdbuf();
// 	std::string content = buffer.str();
// 	if (content.empty()) std::cout << "File is empty";
// 	else if (all_spaces(content)) std::cout << "File is blank";
// 	else std::cout << "File has content";
// 	return 0;
// }
