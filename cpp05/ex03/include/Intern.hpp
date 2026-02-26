#ifndef INTERN_HPP
#define INTERN_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# define	SHRUBBERY	"shrubbery request"
# define	ROBOTOMY	"robotomy request"
# define	PPARDON		"Pardon Request"

class Intern
{
	private:
		std::string _name;

	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm*	makeform(const std::string& formName, const std::string& target);
};


#endif
