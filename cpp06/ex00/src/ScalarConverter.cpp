#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
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
}

std::string	ScalarConverter::charCheck(std::string& literal)
{
	if (literal.length() == 1 && (literal.find_first_not_of("0123456789") != literal.npos))
	{
		_valChar = literal[0];
		return (CHAR);
	}
	return (ERROR);
}

std::string	ScalarConverter::intCheck(std::string& literal)
{

	if (literal.length() <= 11 && !(literal.find_first_not_of("+-0123456789") != literal.npos))
	{
		if (literal.find_first_of('-') != literal.find_last_of('-') || literal.find_first_of('+') != literal.find_last_of('+'))
			return (ERROR);
		if ((literal.find("-") != literal.npos && literal.find("-")) != 0 || (literal.find("+") != literal.npos && literal.find("+") != 0))
			return (ERROR);
		if (atol(literal.c_str()) > INT_MAX || atol(literal.c_str()) < INT_MIN)
			return (ERROR);
		_valInt = atol(literal.c_str());
		return (INT);
	}
	return (ERROR);
}

std::string	ScalarConverter::doubleCheck(std::string& literal)
{
	double tmp;
	if (literal.find_first_of('-') != literal.find_last_of('-') || literal.find_first_of('+') != literal.find_last_of('+'))
		return (ERROR);
	if ((literal.find("-") != literal.npos && literal.find("-") != 0 ) || (literal.find("+") != literal.npos && literal.find("+") != 0))
		return (ERROR);
	if (literal.find("f") != literal.npos)
		return (ERROR);
	if (literal.find_first_not_of("+-0123456789.") !=  literal.npos)
		return (ERROR);
	if (!std::isdigit(literal[literal.find('.') + 1]) || literal.find('.') == 0)
		return (ERROR);
	char *end;
	tmp = strtod(literal.c_str(), &end);
	if (*end == '\0')
	{
		_valDouble = tmp;
		return (DOUBLE);
	}
	else
		return (ERROR);
}

std::string	ScalarConverter::floatCheck(std::string& literal)
{
	size_t sep_pos = literal.find('.');
	size_t findic = literal.find('f');
	if (literal.find_first_of('-') != literal.find_last_of('-') || literal.find_first_of('+') != literal.find_last_of('+'))
		return (ERROR);
	if ((literal.find("-") != literal.npos && literal.find("-") != 0 ) || (literal.find("+") != literal.npos && literal.find("+") != 0))
		return (ERROR);
	if (findic == literal.npos || findic != literal.find_last_of('f') || findic != literal.size() -1 )
		return (ERROR);
	if (literal.at(sep_pos + 1) == 'f')
		return (ERROR);
	if (literal.find_first_not_of("+-0123456789f.") != literal.npos)
		return (ERROR);
	if (sep_pos == literal.npos || sep_pos == 0 || sep_pos == literal.length() || literal.find_last_of('.') != sep_pos)
		return (ERROR);
	std::stringstream ss(literal);
	float num;
	ss >> num;
	if (num != literal.npos)
	{
		_valFloat = num;
		return (FLOAT);
	}
	else
		return (ERROR);
}

std::string	ScalarConverter::pseudoCheck(std::string& literal)
{
	std::string arr[] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
	for (int i = 0; i < 6; i++)
	{
		if (literal == arr[i])
		{
			return (PSEUDO);
		}
	}
	return (ERROR);
}

// Convert method

std::string	ScalarConverter::identify(std::string& literal)
{
	std::string tmp;
	std::string	(ScalarConverter::*func[])(std::string& literal) = \
	{&ScalarConverter::charCheck, &ScalarConverter::intCheck, &ScalarConverter::floatCheck, &ScalarConverter::doubleCheck, &ScalarConverter::pseudoCheck};
	for (int i = 0; i < 5; i++)
	{
		tmp = (this->*func[i])(literal);
		if (!tmp.empty() && tmp != ERROR)
			return tmp;
		if (i == 4 && tmp.empty() && tmp == ERROR)
			return (ERROR);
	}
	return (ERROR);
}

void	ScalarConverter::conversion(std::string& type, std::string& literal)
{
	if (type == CHAR)
	{
		if (!isprint(_valChar))
			std::cout << BLE << "char:\tNon displayable" << RST << std::endl;
		else
			std::cout << BLE << "char:\t\'" << _valChar << "\'"<< RST << std::endl;
		_valInt = static_cast<int>(_valChar);
		std::cout << BLE << "int:\t" << _valInt << RST << std::endl;
		_valFloat = static_cast<float>(_valChar);
		std::cout << std::fixed << std::setprecision(1) << BLE << "float:\t" << _valFloat << "f" << RST << std::endl;
		_valDouble = static_cast<double>(_valChar);
		std::cout << BLE << "double:\t" << _valDouble << RST << std::endl;
	}
	if (type == INT)
	{
		if (_valInt <= 127 && _valInt > -1)
		{
			_valChar = static_cast<char>(_valInt);
			if (!isprint(_valChar))
				std::cout << BLE << "char:\tNon displayable" << RST << std::endl;
			else
				std::cout << BLE << "char:\t\'" << _valChar << "\'"<< RST << std::endl;
		}
		else
			std::cout << BLE << "char:\t" << "impossible" << RST << std::endl;
		std::cout << BLE << "int:\t" << _valInt << RST << std::endl;
		_valFloat = static_cast<float>(_valInt);
		std::cout << std::fixed << BLE << "float:\t" << std::setprecision(1) << _valFloat << "f" << RST << std::endl;
		_valDouble = static_cast<double>(_valInt);
		std::cout << std::fixed << BLE << "double:\t" << std::setprecision(1) << _valDouble << RST << std::endl;
	}
	if (type == FLOAT)
	{
		if (_valFloat <= 127 && _valFloat >= 0)
		{
			_valChar = static_cast<char>(_valFloat);
			if (!isprint(_valChar))
				std::cout << BLE << "char:\tNon displayable" << RST << std::endl;
			else
				std::cout << BLE << "char:\t\'" << _valChar << "\'"<< RST << std::endl;
		}
		else
			std::cout << BLE << "char:\t" << "impossible" << RST << std::endl;
		_valInt = static_cast<int>(_valFloat);
		if (_valInt == INT_MIN)
			std::cout << BLE << "int:\t" << "impossible" << RST << std::endl;
		else
			std::cout << BLE << "int:\t" << _valInt << RST << std::endl;
		std::cout << std::fixed << std::setprecision(1) << BLE << "float:\t" << _valFloat << "f" << RST << std::endl;
		_valDouble = static_cast<double>(_valFloat);
		std::cout << std::fixed << BLE << "double:\t" << std::setprecision(1) << _valDouble << RST << std::endl;
	}
	if (type == DOUBLE)
	{
		if (_valDouble <= 127 && _valDouble >= 0)
		{
			_valChar = static_cast<char>(_valDouble);
			if (!isprint(_valChar))
				std::cout << BLE << "char:\tNon displayable" << RST << std::endl;
			else
				std::cout << BLE << "char:\t\'" << _valChar << "\'"<< RST << std::endl;
		}
		else
			std::cout << BLE << "char:\t" << "impossible" << RST << std::endl;
		_valInt = static_cast<int>(_valDouble);
		if (_valInt == INT_MIN && _valDouble != INT_MIN)
			std::cout << BLE << "int:\timpossible" << RST << std::endl;
		else
			std::cout << BLE << "int:\t" << _valInt << RST << std::endl;
		_valFloat = static_cast<float>(_valDouble);
		std::cout << std::fixed << std::setprecision(1) << BLE << "float:\t" << _valFloat << "f" << RST << std::endl;
		std::cout << std::fixed << BLE << "double:\t" << std::setprecision(1) << _valDouble << RST << std::endl;
	}
	if (type == PSEUDO)
	{
		std::cout << BLE << "char:\timpossible" << RST << std::endl;
		std::cout << BLE << "int:\timpossible" << RST << std::endl;
		if (literal == "nan" || literal == "nanf")
		{
			std::cout << BLE << "float:\tnanf" << RST << std::endl;
			std::cout << BLE << "double:\tnan" << RST << std::endl;
		}
		if (literal.find("-") != literal.npos && literal.find("inf"))
		{
			std::cout << BLE << "float:\t-inff" << RST << std::endl;
			std::cout << BLE << "double:\t-inf" << RST << std::endl;
		}
		if (literal.find("+") != literal.npos && literal.find("inf"))
		{
			std::cout << BLE << "float:\t+inff" << RST << std::endl;
			std::cout << BLE << "double:\t+inf" << RST << std::endl;
		}
	}
}

void	ScalarConverter::convert(std::string& literal)
{
	std::string type;
	ScalarConverter a = ScalarConverter();
	type = a.identify(literal) ;
	if (type == ERROR)
	{
		std::cout << RED << "Incorrect format, try again." << RST << std::endl;
		return ;
	}
	std::cout << YLL << std::string(60, '-') << RST << std::endl;
	a.conversion(type, literal);
	std::cout << YLL << std::string(60, '-') << RST << std::endl;

}
