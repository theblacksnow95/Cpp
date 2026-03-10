#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include <limits.h>
# include <cstdlib>
# include <sstream>

# define	CHAR	"CHAR"
# define	INT		"INT"
# define	FLOAT	"FLOAT"
# define	DOUBLE	"DOUBLE"
# define	ERROR	"ERROR"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		virtual		~ScalarConverter();
		std::string	charCheck(std::string& literal);
		std::string	intCheck(std::string& literal);
		std::string	floatCheck(std::string& literal);
		std::string	doubleCheck(std::string& literal);
		std::string	identify(std::string& literal);

	public:
		static void	convert(std::string& literal) ;
};


#endif
