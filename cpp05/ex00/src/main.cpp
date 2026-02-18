#include "Bureaucrat.hpp"

int	main ()
{
	{
		try
		{
			std::cout << std::endl << PRL << "Test 1: basic creation and redirection operator." << RST << std::endl;
			Bureaucrat a = Bureaucrat();
			Bureaucrat b = Bureaucrat("Puchy", 80);
			std::cout << BLE <<  a << std::endl << b  << RST << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}
		try
		{
			std::cout << std::endl << PRL << "Test 2: exception, grade too low example." << RST << std::endl;
			Bureaucrat b = Bureaucrat("Puchy", 200);
			Bureaucrat a = Bureaucrat();
			std::cout << a << std::endl << b << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}		
		try
		{
			std::cout << std::endl << PRL << "Test 3: exception, grade too high example." << RST << std::endl;
			Bureaucrat b = Bureaucrat("Puchy", 50);
			std::cout << GRN << b << RST << std::endl;
			Bureaucrat a = Bureaucrat("Paco", 0);
			std::cout << a << std::endl << b << std::endl;
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
			std::cout << std::endl << PRL << "Test 4: exception, too high increase and getters check." << RST << std::endl;
			Bureaucrat a("Jean", 2);
			std::cout << "Bureaucrat name ==> " << a.getName() << std::endl;
			std::cout << "Bureaucrat grade ==> " << a.getGrade() << std::endl;
			std::cout << YLL << "Increasing 2 times the grade" << RST << std::endl;
			a.increaseGrade();
			a.increaseGrade();
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}
		try
		{
			std::cout << std::endl << PRL << "Test 5: exception, too low grade." << RST << std::endl;
			Bureaucrat b("example", 149);
			std::cout << GRN << b << RST << std::endl;
			std::cout << YLL << "Decreasing 2 times the grade" << RST << std::endl;
			b.decreaseGrade();
			b.decreaseGrade();
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}
	}
}
