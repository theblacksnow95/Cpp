#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "colors.hpp"

# define override
# define GRADETOOHIGH	"Grade is too high."
# define GRADETOOLOW	"Grade is too low."

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

		std::string		getName() const;
		unsigned int	getGrade() const;
		void			increaseGrade();
		void			decreaseGrade();
		friend std::ostream&	operator<<(std::ostream& os, const Bureaucrat& other);

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



#endif
