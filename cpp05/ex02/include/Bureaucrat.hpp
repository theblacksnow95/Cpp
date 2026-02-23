#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include "colors.hpp"
# include "AForm.hpp"
# include <iostream>
# include <string>

# define GRADETOOHIGH	"Grade is too high."
# define GRADETOOLOW	"Grade is too low."

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
		bool	_validGrade(unsigned int grade) const;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		// getters and member functions
		std::string		getName() const;
		unsigned int	getGrade() const;
		void			increaseGrade();
		void			decreaseGrade();
		
		// added signForm member function
		void	signForm(AForm& form);

		// Custom Exception classes 
		class GradeTooHigh : public std::exception 
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLow : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

// outside the class as we cannot use the 'friend' keyword
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& other);

#endif
