#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat: public WrongAnimal
{
	private:
		std::string	_name;
		Brain		*_brain;
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat&	operator=(const WrongCat& other);
		~WrongCat();

		void	makeSound() const;
		std::string	getIdea() const;
		void	setName(std::string name);
		std::string	getName() const;
};

#endif
