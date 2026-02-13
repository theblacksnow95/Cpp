# include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	mycomp;
	if (ac != 2)
	{	
		std::cout << "Incorrect args: " << YLL  "./HarlFilter [Level]" << RST << std::endl;
		return (1);
	}
	else
	{
		std::string c = av[1];
		mycomp.complain(c);
	}
	return (0);
}
