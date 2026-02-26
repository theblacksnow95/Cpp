#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Form", 72, 45), _target("Unkown")
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("Robotomy Form", 72, 45), _target(target)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm constructor called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target)
{
	_signed = other.getSigned();
	if (DEBUG)
		std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	
	if (this != &other)
	{
		_target = other._target;
		_signed = other.getSigned();
	}
	if (DEBUG)
		std::cout << "RobotomyRequestForm Copy assignment opreator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm Destructor called." << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::checkExecgrade(executor);
	int	num = rand();
	if (num % 3 == 0)
		std::cout << YLL << "\t" << _target << " Has been robotomized successfully" << RST << std::endl;
	else
		std::cout << YLL << "\t" << _target << " robotomization process failed successfully, his remains will be destroyed according to tradition, in the sacred pile of trash." <<  RST << std::endl;

}
