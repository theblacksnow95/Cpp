#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Ascii_form.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
		void	fill_file() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat& executor) const;
};


#endif
