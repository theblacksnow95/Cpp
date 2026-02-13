# include "sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << RED << "Error: incorrect args: " << YLL << "./sed Filename [target s1] [strings2]" << RST << std::endl, 1);
	else
	{
		std::string	fileName = av[1];
		std::string	s1 = av[2];
		std::string	s2 = av[3];
		sed(fileName, s1, s2);
	}
}
