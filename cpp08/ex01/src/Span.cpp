#include "Span.hpp"

Span::Span(): _N(0)
{
}

Span::Span(unsigned int n): _N(n)
{
	if ( n > INT_MAX)
		throw Span::MaxNExc();
	std::cout << GRN << "Span class created with N = " << n << RST << std::endl;
}

Span::Span(const Span& other): _arr(other._arr), _N(other._N)
{
	std::cout << "Span Copy constructor called" << std::endl;
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

void Span::addNumber(int num)
{
	if (_arr.size() + 1 > _N)
		throw Span::OOBouds();
	else
		_arr.push_back(num);
	//std::cout << GRN << num << " added to the class" << RST << std::endl;
}

unsigned int Span::shortestSpan()
{
	int res;
	std::sort(_arr.begin(),_arr.end());

	if (_arr.size() <= 1)
		throw Span::NonSpan();
	else
	{
		res = _arr[1] - _arr[0];
		for (unsigned int i = 1; i < _arr.size(); i++)
		{
			if (_arr[i] - _arr[i - 1] < res)
				res = _arr[i] - _arr[i - 1];
		}
	}
	return (res);
}

unsigned int	Span::longestSpan()
{
	std::sort(_arr.begin(),_arr.end());

	if (_arr.size() <= 1)
		throw Span::NonSpan();
	else
		return (_arr[_arr.size() - 1] - _arr[0]);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_arr.size() + std::distance(begin,end) > _N)
		throw Span::OOBouds();
	_arr.insert(_arr.end(), begin, end);
}

unsigned int Span::getUsed() const
{
	return (_arr.size());
}

unsigned int	Span::getSize() const
{
	return (_N);
}

const char* Span::OOBouds::what() const throw()
{
	return EXCOOB;
}

const char* Span::NonSpan::what() const throw()
{
	return ERRSPAN;
}

const char* Span::MaxNExc::what() const throw()
{
	return EXCMAXN;
}

std::ostream&	operator<<(std::ostream& o, const Span& a)
{
	o << BLE << "Size of class Span: " <<  a.getSize() << RST;
	std::cout << BLE << "\tTotal space used: " << a.getUsed() << RST << std::endl;
	return (o);
}
