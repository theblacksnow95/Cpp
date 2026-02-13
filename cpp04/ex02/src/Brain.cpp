#include "Brain.hpp"

Brain::Brain()
{
	setIdeas("World domination");
	std::cout << "\t" << "Brain Default constructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "\t" << "Brain Copy constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
	std::cout << "\t" << "Brain Copy assignment called" << std::endl;
}

void	Brain::setIdeas(const std::string idea)
{
	std::string tmp = idea;
	if (tmp.empty())
		tmp = "Bewar of the squirrels";
	for (int i = 0; i < 100; i++)
		_ideas[i] = tmp;
}

std::string	Brain::getIdea()
{
	return (_ideas[0]);
}
Brain::~Brain()
{
	std::cout << "\t" << "Brain destructor called" << std::endl;
}
