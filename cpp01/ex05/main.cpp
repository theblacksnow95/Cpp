# include "Harl.hpp"

int	main(void)
{
	Harl	mycomp;
	
	std::cout << YLL << "Printing DEBUG:" << RST << std::endl;
	mycomp.complain("DEBUG");
	std::cout << YLL << "Printing INFO:" << RST << std::endl;
	mycomp.complain("INFO");
	std::cout << YLL << "Printing WARNING:" << RST << std::endl;
	mycomp.complain("WARNING");
	std::cout << YLL << "Printing ERROR:" << RST << std::endl;
	mycomp.complain("ERROR");
	mycomp.complain("");
}
