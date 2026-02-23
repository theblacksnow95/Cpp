#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Paultionaire"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade): _name(name), _grade(grade)
{
	if (!_validGrade(grade))
		std::cout << YLL << "Invalid grade value: " << grade << RST << std::endl;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

bool	Bureaucrat::_validGrade(unsigned int grade) const
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLow();
	if (grade < 1)
		throw Bureaucrat::GradeTooHigh();
	return true;
}

void	Bureaucrat::increaseGrade()
{
	if (_validGrade(_grade - 1))
		_grade  -= 1;
	std::cout << GRN << _name << ": grade increased from: "<< _grade + 1 << ", to : " << _grade << RST << std::endl;	
}

void	Bureaucrat::decreaseGrade()
{
	if (_validGrade(_grade + 1))
		_grade += 1;
	std::cout << GRN << _name << ": grade decreased from: "<< _grade - 1 << ", to: " << _grade << RST << std::endl;
}

const char* Bureaucrat::GradeTooHigh::what() const throw()
{
	std::cout << "Max valid grade is: 1"  <<std::endl;
	return GRADETOOHIGH;
}

const char* Bureaucrat::GradeTooLow::what() const throw()
{
	std::cout << "Min valid grade is: 150" << std::endl;
	return GRADETOOLOW;
}


std::ostream&	operator<<(std::ostream& os, const Bureaucrat& other)
{
	std::cout << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (os);
}

// new signForm function
void	Bureaucrat::signForm(AForm& form) 
{
	if (form.getSigned())
	{
		std::cout << RED << _name << " couldn't sign " << form.getName() << " because the form was already signed" << RST << std::endl;
		return ;
	}
	try 
	{
		form.beSigned(*this);
		if (form.getSigned())
			std::cout << GRN << _name << " signed " << form.getName() << RST << std::endl;
	}
	catch (std::exception & e)
	{
		
		std::cout << YLL << "\tException detected:" << RST << std::endl;
		std::cout << RED << _name << " couldn't sign " << form.getName() << " because " << e.what() << RST << std::endl;
	}
}
// I should use beSigned with a try catch to be able to catch the exception before it gets to a higher level, its cleaner
