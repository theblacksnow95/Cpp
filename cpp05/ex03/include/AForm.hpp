#ifndef AFORM_HPP
#define AFORM_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"

# define GRADETOOHIGH	"Grade is too high."
# define GRADETOOLOW	"Grade is too low."
# define EXECTOOLOW		"Grade is too low to execute this form."
# define SIGNEXECERR	"Form needs to be signed before attempting to execute, you need the stamp on it, take another appointment please."
# define DEBUG			0

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_minGradeSign;
		const unsigned int	_minGradeExec;
		bool				_validGrade(unsigned int grade) const;
	public:
		AForm();
		AForm(const std::string& name, unsigned int minSign, unsigned int minExec);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		~AForm();

		// getters
		std::string		getName() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecGrade() const;
		bool			getSigned() const;

		// member functions
		void			beSigned(const Bureaucrat& Bur);
		virtual void	execute( Bureaucrat const & executor)const = 0;
		void			checkExecgrade(const Bureaucrat& executor) const;

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
		class GradeExecTooLow: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class SignExecError: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

//redirection operator overload 
std::ostream&	operator<<(std::ostream& os, const AForm& other);

#endif
