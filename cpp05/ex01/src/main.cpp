#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main ()
{
	{
		try
		{
			std::cout << std::endl << PRL << "Test 1: basic creation and redirection operator." << RST << std::endl;
			Bureaucrat bur = Bureaucrat();
			Form	a = Form("gen1", 120, 100);
			std::cout << BLE <<  a << RST << std::endl;
			bur.signForm(a);
			std::cout << BLE <<  a << RST << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}

	}
	{
	}
}
