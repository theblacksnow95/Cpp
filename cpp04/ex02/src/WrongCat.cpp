#include "WrongCat.hpp"

// default constructor
WrongCat::WrongCat(): WrongAnimal("WrongCat"), _name("Whiskas")
{
	 _brain = new Brain();
	std::cout << "\t" <<  "WrongCat default constructor" << std::endl;
}

// copy constructor
WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other._type)
{
	_name = other._name;
	_brain = other._brain;
	std::cout << "\t" <<"WrongCat Copy constructor" << std::endl;
}

// copy assignment operator overload
WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		delete _brain;
		_type = other._type;
		_brain = other._brain;
		_name = other._name;
	}
	std::cout << "\t" <<"Copy assignement operator called" << std::endl;
	return (*this);
}

// destructor
WrongCat::~WrongCat()
{
	 delete _brain;
	std::cout << "\t" <<"WrongCat Destructor called" << std::endl;
}

std::string	WrongCat::getIdea() const
{
	return(_brain->getIdea());
}

void	WrongCat::setName(std::string name)
{
	_name = name;
}

std::string	WrongCat::getName() const
{
	return (_name);
}

// WrongCat sound member
void	WrongCat::makeSound() const
{
	std::cout << "Make sound called: " << std::endl << "\t";
	std::cout << "The WrongCat says: nyan nyan nyan nyan nyan nyan nyan nyan nyan nyan" << std::endl;
}
