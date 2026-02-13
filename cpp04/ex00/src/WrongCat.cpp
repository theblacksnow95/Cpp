#include "WrongCat.hpp"

// default constructor
WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "\t" <<  "WrongCat default constructor" << std::endl;
}

// copy constructor
WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other._type)
{
	std::cout << "\t" <<"WrongCat Copy constructor" << std::endl;
}
// copy assignment operator overload
WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		_type =  other._type;
	std::cout << "\t" <<"Copy assignement operator called" << std::endl;
	return (*this);
}

// destructor
WrongCat::~WrongCat()
{
	std::cout << "\t" <<"WrongCat Destructor called" << std::endl;
}

// WrongCat sound member
void	WrongCat::makeSound() const
{
	std::cout << "Make sound called: " << std::endl << "\t";
	std::cout << "The WrongCat says: nyan nyan nyan nyan nyan nyan nyan nyan nyan nyan" << std::endl;
}
