#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5), _target("Unkown")
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("Presidential pardon Form", 25, 5), _target(target)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm  constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other), _target(other._target)
{
	_signed = other.getSigned();
	if (DEBUG)
		std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		_signed = other.getSigned();
		_target = other._target;
	}
	if (DEBUG)
		std::cout << "PresidentialPardonForm Copy assignment opreator called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::checkExecgrade(executor);
	std::cout << YLL << "\t" << "Presidential pardon issued by  Zaphod Beeblebrox for " << _target  << ". Voluntary donation received correctly, in a safe location. (+) " << RST << std::endl;
}
