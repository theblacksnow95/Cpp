#include "Bureaucrat.hpp"

int	main ()
{
	{
		try
		{
			Bureaucrat b = Bureaucrat("algo", 150);
			Bureaucrat a = Bureaucrat("name", 1);
			std::cout << b.getName() << " , bureaucrat grade " << b.getGrade() << std::endl;
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
