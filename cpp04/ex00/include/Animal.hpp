#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <string>

# define GRN	"\033[0;32m"
# define YLL	"\033[0;33m"
# define RED	"\033[0;31m"
# define RST	"\033[0m"

class Animal
{
	protected:
		std::string _type;
	public:
		// orthodox form
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		std::string	getType() const;
		void	setType(const std::string& type) ;
		virtual void	makeSound() const;
};



#endif
