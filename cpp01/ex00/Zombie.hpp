#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

# define GRN	"\033[0;32m"
# define YLL	"\033[0;33m"
# define RED	"\033[0;31m"
# define RST	"\033[0m"

class Zombie
{
private:
	std::string	_name;
public:
	// constructor
	Zombie();
	Zombie(std::string &name);
	// member function
	void	announce(void);
	~Zombie();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
