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

const char* Intern::WrongFormNameException::what() const throw()
{
	return WRONGFORMNAME;
}

AForm* Intern::ShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::RobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::PardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeform(const std::string& formName, const std::string& target)
{
	AForm *tmp = NULL;
	std::string arr[] = {"shrubbery request", "robotomy request", "pardon request"};
	AForm*	(Intern::*func[])(const std::string& target) = {&Intern::ShrubberyForm, &Intern::RobotomyForm, &Intern::PardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == formName)
			tmp = (this->*func[i])(target);
		if (i == 2 && !tmp)
			throw Intern::WrongFormNameException();
	}
	std::cout << YLL << "\tIntern creates: " << tmp->getName() << RST << std::endl;
	return tmp;
}
