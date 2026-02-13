#include "Cat.hpp"

// default constructor
Cat::Cat(): Animal("Cat"), _name(new std::string("Mr Mittens")), _brain(new Brain())
{
	
	std::cout << "\t" << GRN << "Cat default constructor" << RST << std::endl;
}

// copy constructor
Cat::Cat(const Cat& other): Animal(other._type)
{
	if (other._brain != NULL)
		_brain = new Brain(*other._brain);
	else
		_brain = NULL;
	if (other._name != NULL)
		_name = new std::string(*other._name);
	else
		_name = NULL;
	std::cout << "\t" << "Cat Copy constructor" << std::endl;
}

// copy assignment operator overload
Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		// delete _brain;
		delete _name;
		_type =  other._type;
		if (other._brain != NULL)
			*_brain = *other._brain;
		else
			_brain = NULL;
		if (other._name != NULL)
			_name = new std::string(*(other._name));
		else
			_name = NULL;
	}
	std::cout << "\t" << "Copy assignement operator called" << std::endl;
	return (*this);
}

// destructor
Cat::~Cat()
{
	delete _brain;
	delete _name;
	std::cout << "\t" << RED << "Cat Destructor called" << RST << std::endl;
}

std::string	Cat::getIdea() const
{
	return(_brain->getIdea());
}

std::string Cat::getName() const
{
	return (*_name);
}

void	Cat::setName(std::string name)
{
	*_name = name;
	// *(_name) = (name) it's the same, thing more clear
}

// cat sound member
void	Cat::makeSound() const
{
	std::cout << "\t" << "Make sound called: " << std::endl << "\t";
	std::cout << "\t" << "The Cat says: nyan nyan nyan nyan nyan nyan nyan nyan nyan nyan" << std::endl;
}
