#include "Animal.hpp"
// default constructor
Animal::Animal(): _type("Unknown")
{
	std::cout << "\t" << "Animal Default contructor called" << std::endl;
}
// Type constructor
Animal::Animal(const std::string& type)
{
	if (type.empty())
		_type = "Unknown";
	else
		_type = type;
	std::cout << "\t" << "Animal constructor called" << std::endl;
}
// Copy constructor
Animal::Animal(const Animal& other)
{
	_type = other._type;
	std::cout << "\t" << "Copy constructor called" << std::endl;

}
// Copy assignment operator overload
Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
	std::cout << "\t" << "Copy assignment operator called" << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "\t" << "Animal Destructor called." << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}

void	Animal::setType(const std::string& type)
{
	if (type.empty())
		_type = "Unkown";
	else
		_type = type;
}

void	Animal::makeSound() const
{
	std::cout << "\t" << "Make sound called: " << std::endl << "\t";
	std::cout << "\t" << "Animal sound.\n" ;
}
