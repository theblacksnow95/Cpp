#include "Bureaucrat.hpp"

int	main ()
{
	{
		try
		{
			std::cout << std::endl << PRL << "Test 1: basic creation and redirection operator." << RST << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\tException detected:" << RST << std::endl;
			std::cerr << RED << e.what() << RST << std::endl;
		}
	}
}
