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

// Convert method

void	identify(std::string& literal)
{
	if (literal.length() == 1 && (!literal.find_first_not_of("0123456789") == literal.npos))
	{
		
	}
	if (literal.find_first_not_of("0123456789") == literal.npos)
	{

	}
	else

}


void	ScalarConverter::convert(std::string& literal) const
{
	identify(literal);
}
