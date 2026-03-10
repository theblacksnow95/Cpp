#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
	std::cout << "ScalarConverter Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{

	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called." << std::endl;
}

std::string	ScalarConverter::charCheck(std::string& literal)
{
	if (literal.length() == 1 && (literal.find_first_not_of("0123456789") != literal.npos))
	{
		return (CHAR);
	}
	return (ERROR);
}

std::string	ScalarConverter::intCheck(std::string& literal)
{

	if (literal.length() <= 11 && !(literal.find_first_not_of("-0123456789") != literal.npos))
	{
		if (literal.find("-") != literal.npos && literal.find("-") != 0)
			return (ERROR);
		if (atol(literal.c_str()) > INT_MAX || atol(literal.c_str()) < INT_MIN)
			return (ERROR);
		return (INT);
	}
	return (ERROR);
}

std::string	ScalarConverter::floatCheck(std::string& literal)
{
	size_t sep_pos = literal.find(".");
	if (literal.find("f") == literal.npos)
		return (ERROR);
	if ((literal.find_first_not_of("-0123456789f.") != literal.npos))
		return (ERROR);
	if (sep_pos == literal.npos || sep_pos == 0 || sep_pos == literal.length() || literal.find_last_of(".") != sep_pos)
		return (ERROR);
	std::stringstream ss(literal);
	float num;
	ss >> num;
	if (num)
		return (FLOAT);
	else
		return (ERROR);
}

// Convert method

std::string	ScalarConverter::identify(std::string& literal)
{
	std::string tmp;
	std::string	(ScalarConverter::*func[])(std::string& literal) = {&ScalarConverter::charCheck, &ScalarConverter::intCheck, &ScalarConverter::floatCheck};
	for (int i = 0; i < 3; i++)
	{
		tmp = (this->*func[i])(literal);
		if (!tmp.empty() && tmp != ERROR)
			return tmp;
		if (i == 1 && tmp.empty() && tmp == ERROR)
			return (ERROR);
	}
	return ERROR;
}


void	ScalarConverter::convert(std::string& literal)
{
	std::string type;
	ScalarConverter a = ScalarConverter();
	type = a.identify(literal) ;
	std::cout << YLL << type << RST << std::endl;

}
