#include "Span.hpp"


Span::Span(unsigned int N): _N(N)
{
	std::cout << GRN << "Span class created with N = " << N << RST << std::endl;
}

Span::Span(const Span& other): _arr(other._arr), _N(other._N)
{
	std::cout << "Span Copy constructor called" << std::endl;
}

void Span::addNumber(int num)
{
	if (_arr.size() + 1 > _N)
		throw Span::OOBouds();
	else
		_arr.push_back(num);
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_arr = other._arr;
		_N = other._N;
	}
	std::cout << "Copy Assignment operator called" << RST << std::endl;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span Destructor called." << std::endl;
}

unsigned int	Span::getSize() const
{
	return (_N);
}

const char* Span::OOBouds::what() const throw()
{
	return EXCOOB;
}

std::ostream&	operator<<(std::ostream& o, const Span& a)
{
	o << BLE << "Size of class Span: " <<  a.getSize() << RST;
	return (o);
}
