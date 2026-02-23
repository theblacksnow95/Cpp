#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include "AForm.hpp"
# define TREE "|-\n|-cd\n|-ex00\n|---include\n|---obj\n|---src\n|-ex01\n|---include\n|---obj\n|---src\n|-ex02\n|---include\n|---src"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};


#endif
