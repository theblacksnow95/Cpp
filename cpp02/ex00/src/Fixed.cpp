#include "Fixed.hpp"

int const Fixed::_frBits = 8;


// Default constructor
Fixed::Fixed(): _fpValue(0)
{
	std::cout << "Default constructor Fixed called." << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called." << std::endl;
	_fpValue = other.getRawBits();
}

//copy assignment operator overload
Fixed& Fixed::operator = (const Fixed& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
		_fpValue = int(other._fpValue);
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor Fixed called." << std::endl;
}


int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return _fpValue;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called." << std::endl;

	this->_fpValue = raw;
}
