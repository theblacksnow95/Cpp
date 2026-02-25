#include "ShrubberyCreationForm.hpp"

void	fill_file(std::ofstream& outfile);


ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137)
{
	std::ofstream	outfile("default_shrubbery");
	fill_file(outfile);
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("Shrubbery", 145, 137)
{
	std::ofstream	outfile((target + "_shrubbery").c_str());
	fill_file(outfile);
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
	_signed = other.getSigned();
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	
	if (this != &other)
	{
		_signed = other.getSigned();
	}
	std::cout << "ShrubberyCreationForm Copy assignment opreator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat& bur)
{
	if (_signed)
	{
		std::cout << "form already signed" << std::endl;
		return ;
	}
	if (bur.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	fill_file(std::ofstream& outfile)
{
	outfile << ASCIITREE << std::endl;
}
