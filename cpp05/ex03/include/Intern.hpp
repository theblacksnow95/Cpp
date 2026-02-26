#ifndef INTERN_HPP
#define INTERN_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# define	WRONGFORMNAME	"Requested form does not exist, cannot create a form."

class Intern
{
	private:
		std::string _name;
		AForm*	ShrubberyForm(const std::string& target);
		AForm*	RobotomyForm(const std::string& target);
		AForm*	PardonForm(const std::string& target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm*	makeform(const std::string& formName, const std::string& target);

		class WrongFormNameException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};


#endif
