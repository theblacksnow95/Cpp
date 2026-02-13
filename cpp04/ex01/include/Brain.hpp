#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	protected:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		void	setIdeas(const std::string idea);
		std::string	getIdea();
		~Brain();
};

#endif
