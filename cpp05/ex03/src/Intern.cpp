#include "Intern.hpp"

Intern::Intern()
{
	if (DEBUG)
		std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	if (DEBUG)
		std::cout << "Intern Copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	
	if (this != &other)
	{
		*this = other;
	}
	if (DEBUG)
		std::cout << "Intern Copy assignment opreator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	if (DEBUG)
		std::cout << "Intern Destructor called." << std::endl;
}


AForm*	Intern::makeform(const std::string& formName, const std::string& target)
{
	// if (formName == SHRUBBERY)
	// {
	// 	return (new ShrubberyCreationForm(target));
	// }
	if (formName != SHRUBBERY)
		throw 
	return new
}
