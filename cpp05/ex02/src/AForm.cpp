#include "AForm.hpp"

AForm::AForm():_name("Generic AForm"), _signed(false), _minGradeSign(150), _minGradeExec(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}


AForm::AForm(const std::string& name, unsigned int minSign, unsigned int minExec): _name(name), _signed(false), _minGradeSign(minSign), _minGradeExec(minExec)
{
	_validGrade(minSign);
	_validGrade(minExec);
	std::cout << "AForm Constructor called" << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name),  _signed(other._signed), _minGradeSign(other._minGradeSign), _minGradeExec(other._minGradeExec)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	
	if (this != &other)
	{
		_signed = other._signed;
	}
	std::cout << "AForm Copy assignment opreator called" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called." << std::endl;
}

// getters

std::string	AForm::getName() const
{
	return (_name);
}

unsigned int AForm::getSignGrade() const
{
	return (_minGradeSign);
}

unsigned int AForm::getExecGrade() const
{
	return (_minGradeExec);
}

bool	AForm::getSigned() const
{
	if (_signed)
		return (true);
	else
		return (false);
}

// grade validation and custom exception classes 

bool	AForm::_validGrade(unsigned int grade) const
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	if (grade < 1)
		throw AForm::GradeTooHighException();
	return true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	// std::cout << "Max possible grade is: 1" << std::endl;
	return GRADETOOHIGH;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	// std::cout << "Min posssible grade is: 150" << std::endl;
	return GRADETOOLOW;
}


// beSigned member funtion
void	AForm::beSigned(const Bureaucrat& Bur)
{
	if (_signed)
	{
		std::cout << "form already signed" << std::endl;
		return ;
	}
	if (Bur.getGrade() > this->getSignGrade())
	{
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

// redirection override operator
std::ostream&	operator<<(std::ostream& os, const AForm& other)
{
	std::cout << other.getName() << ", form has the next parameters: " << std::endl;
	std::cout << "\tGrade required to be signed:\t" << other.getSignGrade() << std::endl;
	std::cout << "\tGrade required to be executed:\t" << other.getExecGrade() << std::endl;
	std::cout << "\tCurrent sign status:\t\t" << std::boolalpha << other.getSigned() << std::endl;
	return (os);
}

void	AForm::execute(const Bureaucrat& executor)
{
	 
}
