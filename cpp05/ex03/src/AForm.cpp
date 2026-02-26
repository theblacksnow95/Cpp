#include "AForm.hpp"

AForm::AForm():_name("Generic AForm"), _signed(false), _minGradeSign(150), _minGradeExec(150)
{
	if (DEBUG)
		std::cout << "AForm Default constructor called" << std::endl;
}


AForm::AForm(const std::string& name, unsigned int minSign, unsigned int minExec): _name(name), _signed(false), _minGradeSign(minSign), _minGradeExec(minExec)
{
	_validGrade(minSign);
	_validGrade(minExec);
	if (DEBUG)
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
	if (DEBUG)
		std::cout << "AForm Copy assignment opreator called" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	if (DEBUG)
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
	return GRADETOOHIGH;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return GRADETOOLOW;
}

const char* AForm::GradeExecTooLow::what() const throw()
{
	return EXECTOOLOW;
}
const char* AForm::SignExecError::what() const throw()
{
	return SIGNEXECERR;
}



// beSigned member funtion
void	AForm::beSigned(const Bureaucrat& Bur)
{
	if (_signed)
	{
		std::cout << "\tForm already signed" << std::endl;
		return ;
	}
	if (Bur.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

// redirection override operator
std::ostream&	operator<<(std::ostream& os, const AForm& other)
{
	std::cout << "\t" << other.getName() << ", form has the next parameters: " << std::endl;
	std::cout << "\t\tGrade required to be signed:\t" << other.getSignGrade() << std::endl;
	std::cout << "\t\tGrade required to be executed:\t" << other.getExecGrade() << std::endl;
	std::cout << "\t\tCurrent sign status:\t\t" << std::boolalpha << other.getSigned() << std::endl;
	return (os);
}

void AForm::checkExecgrade(const Bureaucrat& executor) const
{
	if (!this->getSigned())
		throw AForm::SignExecError();
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeExecTooLow();
	else
		std::cout << GRN << "\tGrade check: passed, " << executor.getName() << " Can execute the form: " << this->getName()<< RST << std::endl;
}
