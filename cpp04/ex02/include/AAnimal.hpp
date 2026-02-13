#ifndef AANIMAL_HPP
#define AANIMAL_HPP

# include <iostream>
# include <string>

# define GRN	"\033[0;32m"
# define YLL	"\033[0;33m"
# define RED	"\033[0;31m"
# define RST	"\033[0m"
# define N_ARR	6

class AAnimal
{
	protected:
		std::string _type;
	public:
		// orthodox form
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();
		std::string	getType() const;
		void	setType(const std::string& type) ;
		virtual void	makeSound() const = 0;
};



#endif
