#include "Cat.hpp"

// default constructor
Cat::Cat(): Animal("Cat")
{
	std::cout << "\t" << "Cat default constructor" << std::endl;
}

// copy constructor
Cat::Cat(const Cat& other): Animal(other._type)
{
	std::cout << "\t" << "Cat Copy constructor" << std::endl;
}
// copy assignment operator overload
Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
		_type =  other._type;
	std::cout << "\t" << "Copy assignement operator called" << std::endl;
	return (*this);
}

// destructor
Cat::~Cat()
{
	std::cout << "\t" << "Cat Destructor called" << std::endl;
}

// cat sound member
void	Cat::makeSound() const
{
	std::cout << "\t" << "Make sound called: " << std::endl << "\t";
	std::cout << "\t" << "The Cat says: nyan nyan nyan nyan nyan nyan nyan nyan nyan nyan" << std::endl;
}
