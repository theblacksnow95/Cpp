#include "Form.hpp"

Form::Form():_name("Generic Form"), _signed(false), _minGradeSign(150), _minGradeExec(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}


Form::Form(const std::string& name, unsigned int minSign, unsigned int minExec): _name(name), _minGradeSign(minSign), _minGradeExec(minExec)
{
	_validGrade(minSign);
	_validGrade(minExec);
	std::cout << "Form Constructor called" << std::endl;
}

Form::Form(const Form& other): _name(other._name),  _signed(other._signed), _minGradeSign(other._minGradeSign), _minGradeExec(other._minGradeExec)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	
	if (this != &other)
	{
		_signed = other._signed;
	}
	std::cout << "Form Copy assignment opreator called" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form Destructor called." << std::endl;
}

// getters

std::string	Form::getName() const
{
	return (_name);
}

unsigned int Form::getSignGrade() const
{
	return (_minGradeSign);
}

unsigned int Form::getExecGrade() const
{
	return (_minGradeExec);
}

bool	Form::getSigned() const
{
	if (_signed)
		return (true);
	else
		return (false);
}

// grade validation and custom exception classes 

bool	Form::_validGrade(unsigned int grade) const
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
	return true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	// std::cout << "Max possible grade is: 1" << std::endl;
	return GRADETOOHIGH;
}

const char* Form::GradeTooLowException::what() const throw()
{
	// std::cout << "Min posssible grade is: 150" << std::endl;
	return GRADETOOLOW;
}


// beSigned member funtion
void	Form::beSigned(const Bureaucrat& Bur)
{
	if (_signed)
	{
		std::cout << "form already signed" << std::endl;
		return ;
	}
	if (Bur.getGrade() > this->getSignGrade())
	{
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
}

// redirection override operator
std::ostream&	operator<<(std::ostream& os, const Form& other)
{
	std::cout << other.getName() << ", form has the next parameters: " << std::endl;
	std::cout << "\tGrade required to be signed:\t" << other.getSignGrade() << std::endl;
	std::cout << "\tGrade required to be executed:\t" << other.getExecGrade() << std::endl;
	std::cout << "\tCurrent sign status:\t\t" << std::boolalpha << other.getSigned() << std::endl;
	return (os);
}
