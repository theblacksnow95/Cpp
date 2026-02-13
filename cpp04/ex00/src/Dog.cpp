#include "Dog.hpp"

// Default constructor
Dog::Dog(): Animal("Dog")
{
	std::cout << "\t" << "Dog Default constructor." << std::endl;
}
// Copy constructor
Dog::Dog(const Dog& other): Animal(other._type)
{
	std::cout << "\t" << "Dog Copy constructor" << std::endl;
	
}
// Copy assignement operator overload
Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}
// destructor
Dog::~Dog()
{
	std::cout << "\t" << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "\t" << "Make sound called: " << std::endl << "\t";
	std::cout << "\t" << "The (OG) Dog does: Wof Wof beaches" << std::endl;
}
