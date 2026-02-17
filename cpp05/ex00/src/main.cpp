#include "Bureaucrat.hpp"

int	main ()
{
	try 
	{
		Bureaucrat b = Bureaucrat("algo", 100);
		std::cout << b.getName() << " , bureaucrat grade " << b.getGrade() << std::endl;
		Bureaucrat a = Bureaucrat("name", 200);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RST << std::endl;
	}
}
