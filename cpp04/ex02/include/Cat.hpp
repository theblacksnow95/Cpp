#ifndef CAT_HPP
#define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{	
	private:
		std::string	*_name;
		Brain	*_brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();

		void	makeSound() const;
		std::string	getIdea() const;
		std::string	getName() const;
		void	setName(std::string name);
};

#endif
