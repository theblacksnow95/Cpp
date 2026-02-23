#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main ()
{
	{
		try
		{
			std::cout << std::endl << PRL << "Test 1: basic creation and redirection operator." << RST << std::endl;
			Bureaucrat bur = Bureaucrat("Paul", 100);
			std::cout << BLE << bur << RST << std::endl;
			std::cout << YLL << "Trying to sign form" << RST << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}
	}
}
