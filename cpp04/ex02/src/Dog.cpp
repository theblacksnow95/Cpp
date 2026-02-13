#include "Dog.hpp"

// Default constructor
Dog::Dog(): AAnimal("Dog")
{
	_brain = new Brain();
	std::cout << "\t" << GRN << "Dog Default constructor." << RST << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other): AAnimal(other._type)
{
	_brain = new Brain(*other._brain);
	if (!other._brain)
		_brain = NULL;
	std::cout << "\t" << "Dog Copy constructor" << std::endl;
}

// Copy assignement operator overload
Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		delete _brain;
		_type = other._type;
		_brain = new Brain(*(other._brain));
		if (!other._brain)
			_brain = NULL;
	}
	return (*this);
}

// destructor
Dog::~Dog()
{
	delete _brain;
	std::cout << "\t" << RED << "Dog destructor called" << RST << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "\t" << "Make sound called: " << std::endl << "\t";
	std::cout << "\t" << "The (OG) Dog does: Wof Wof beaches" << std::endl;
}
