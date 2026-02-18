#ifndef FORM_HPP
#define FORM_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

# define GRADETOOHIGH	"Grade is too high."
# define GRADETOOLOW	"Grade is too low."

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_minGradeSign;
		const unsigned int	_minGradeExec;
		bool				_validGrade(unsigned int grade) const;
	public:
		Form();
		Form(const std::string& name, unsigned int minSign, unsigned int minExec);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form();

		// getters
		std::string		getName() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecGrade() const;
		bool			getSigned() const;

		// member functions
		void	beSigned(const Bureaucrat& Bur);

		// Custom exception classes
		class GradeTooHighException: public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

//redirection operator overload 
std::ostream&	operator<<(std::ostream& os, const Form& other);

#endif
