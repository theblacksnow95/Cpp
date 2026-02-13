#include "AAnimal.hpp"
// default constructor
AAnimal::AAnimal(): _type("Unknown")
{
	std::cout << "\t" << "AAnimal Default contructor called" << std::endl;
}
// Type constructor
AAnimal::AAnimal(const std::string& type)
{
	if (type.empty())
		_type = "Unknown";
	else
		_type = type;
	std::cout << "\t" << "AAnimal constructor called" << std::endl;
}
// Copy constructor
AAnimal::AAnimal(const AAnimal& other)
{
	_type = other._type;
	std::cout << "\t" << "Copy constructor called" << std::endl;

}
// Copy assignment operator overload
AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
	std::cout << "\t" << "Copy assignment operator called" << std::endl;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "\t" << "AAnimal Destructor called." << std::endl;
}

std::string	AAnimal::getType() const
{
	return (_type);
}

void	AAnimal::setType(const std::string& type)
{
	if (type.empty())
		_type = "Unkown";
	else
		_type = type;
}

void	AAnimal::makeSound() const
{
	std::cout << "\t" << "Make sound called: " << std::endl << "\t";
	std::cout << "\t" << "AAnimal sound.\n" ;
}
