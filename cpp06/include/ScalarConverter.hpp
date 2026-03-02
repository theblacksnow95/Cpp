#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include "colors.hpp"
# include <iostream>
#include <string>

class ScalarConverter
{
	private:
		std::string	_literal;

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter();
};


#endif
