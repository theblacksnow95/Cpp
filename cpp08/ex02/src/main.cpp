#include "MutantStack.hpp"

std::ostream&	operator<<(std::ostream& o, const std::vector<int> a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		o << a[i] << " " ;
	}
	return (o);
}

void	fastAdd(Span& a, unsigned int n)
{

	for (unsigned int i = 0; i < n; i++)
	{
		long int num = rand();
		a.addNumber(num);
	}
}

int main()
{
	srand(time(NULL));
	Span a = Span(5);
	Span b(10);
	Span c = Span(20000);
	std::vector<int> fill(10, 12);
	std::cout << RED << "\t" << "test container: " << fill << RST << std::endl;
	try
	{
		std::cout << PRL << "Basic test: addNumber" << RST << std::endl;
		a.addNumber(9);
		a.addNumber(11);
		a.addNumber(3);
		a.addNumber(6);
		a.addNumber(17);
		b.addNumber(fill.begin(), fill.end());
		std::cout << "\t" << "Shortest Span: " << a.shortestSpan() << std::endl;
		std::cout << "\t" << "Longest Span: " << a.longestSpan() << std::endl;
		std::cout << "\t" << "Shortest Span: " << b.shortestSpan() << std::endl;
		std::cout << "\t" << "Longest Span: " << b.longestSpan() << std::endl;

		std::cout << "\t" << a << std::endl;
		std::cout << "\t" << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << YLL << "Exception detected: " << RST << std::endl;
		std::cout << RED << "\t" << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << PRL << "Test with multiple values" << RST << std::endl;
		fastAdd(c, 19999);
		std::cout << "Shortest span c: " <<c.shortestSpan() << RST << std::endl;
		std::cout << "Shortest span c: " <<c.longestSpan() << RST << std::endl;
		std::cout << "\t" << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << YLL << "Exception detected: " << RST << std::endl;
		std::cerr << RED << "\t" << e.what() << RST << '\n';
	}
	try
	{
		std::cout << PRL << "Test incorrect initialisation" << RST << std::endl;
		Span test = Span((2147483648));
	}
	catch(const std::exception& e)
	{
		std::cout << YLL << "Exception detected: " << RST << std::endl;
		std::cerr << RED << "\t" << e.what() << RST <<  '\n';
	}

	return (0);
}
