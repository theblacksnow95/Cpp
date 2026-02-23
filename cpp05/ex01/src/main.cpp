#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main ()
{
	{
		try
		{
			std::cout << std::endl << PRL << "Test 1: basic creation and redirection operator." << RST << std::endl;
			Bureaucrat bur = Bureaucrat("Paul", 100);
			Form	a = Form("Form1", 120, 100);
			std::cout << BLE <<  a << RST << std::endl;
			std::cout << BLE << bur << RST << std::endl;
			std::cout << YLL << "Trying to sign form" << RST << std::endl;
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
		try
		{
			std::cout << std::endl << PRL << "Test 2: Sign a form with correct and incorrect grade." << RST << std::endl;
			Bureaucrat func("BUROCRAT", 100);
			Form a("Form2", 120, 100);
			Form b("Form3", 90, 100);
			std::cout << YLL << "Trying to sign form" << RST << std::endl;
			func.signForm(a);
			func.signForm(a);
			func.signForm(b);
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}
		try
		{
			std::cout << std::endl << PRL << "Test 3: Form with incorrect grade." << RST << std::endl;
			Form a("Incorrect exec", 120, 0);
			Form b("incorrect sign", 200, 100);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RST << std::endl;
		}
		
	}
}
