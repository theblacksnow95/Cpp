#include "Bureaucrat.hpp"

int	main ()
{
	{
		try
		{
			Bureaucrat b = Bureaucrat("Puchy", 150);
			Bureaucrat a = Bureaucrat();
			std::cout << a << std::endl << b << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RST << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat a("make", 2);
			a.increaseGrade();
			a.increaseGrade();
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RST << std::endl;
		}
		try
		{
			Bureaucrat b("other", 150);
			b.decreaseGrade();
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RST << std::endl;
		}
	}
}
