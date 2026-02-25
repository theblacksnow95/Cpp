#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Ascii_form.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void	beSigned(const Bureaucrat& bur);
		void	executeForm(const Bureaucrat& executor) const;
};


#endif
