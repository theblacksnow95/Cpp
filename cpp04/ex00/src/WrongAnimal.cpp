#include "WrongAnimal.hpp"

// default constructor
WrongAnimal::WrongAnimal(): _type("Unknown")
{
	std::cout << "\t" << "WrongAnimal Default contructor called" << std::endl;
}
// Type constructor
WrongAnimal::WrongAnimal(const std::string& type)
{
	if (type.empty())
		_type = "Unknown";
	else
		_type = type;
	std::cout << "\t" << "WrongAnimal constructor called" << std::endl;
}
// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	_type = other._type;
	std::cout << "\t" << "Copy constructor called" << std::endl;

}
// Copy assignment operator overload
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
	std::cout << "\t" << "Copy assignment operator called" << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\t" << "WrongAnimal Destructor called." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "\t" << "Wrong Make sound called.\n" << "\t" ;
	std::cout << "\t" << "There is definetly something wrong with this animal, kill it!\n" ;
}
