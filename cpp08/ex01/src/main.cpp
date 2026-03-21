#include "Span.hpp"

int main()
{
	Span a(3);
	try
	{
	a.addNumber(2445);
	a.addNumber(2445);
	a.addNumber(2445);
	std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << YLL << "Exception detected: " << RST << std::endl;
		std::cout << RED << "\t" << e.what() << RST << std::endl;
	}
	return (0);
}
