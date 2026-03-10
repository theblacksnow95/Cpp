#include "ScalarConverter.hpp"

int	main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << YLL << "ERROR: invalid args." << RST << std::endl;
		return (1);
	}
	else
	{
		std::string input = av[1];
		ScalarConverter::convert(input);
	}
}
