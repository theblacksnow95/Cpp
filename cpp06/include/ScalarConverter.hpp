#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include "colors.hpp"
# include <iostream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		virtual ~ScalarConverter();

		void	convert(std::string& literal) const;
};


#endif
