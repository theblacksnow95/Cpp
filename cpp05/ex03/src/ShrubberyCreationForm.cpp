#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137)
{
	_target = "Unkown";
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("Shrubbery", 145, 137), _target(target)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target)
{
	_signed = other.getSigned();
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{

	if (this != &other)
	{
		_target = other._target;
		_signed = other.getSigned();
	}
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Copy assignment opreator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}

void	ShrubberyCreationForm::fill_file() const
{
	std::ofstream	outfile((_target + "_shrubbery").c_str());
	outfile << ASCIITREE << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::checkExecgrade(executor);
	std::cout << GRN << "\t" << "Executing Shrubbery Form. The trees are growing fast...." << RST << std::endl;
	this->fill_file();
}
