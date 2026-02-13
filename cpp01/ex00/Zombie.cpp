#include "Zombie.hpp"

Zombie::Zombie(): _name("Chowder")
{
	std::cout << '\t' << "Zombie created with default name Chowder" << std::endl;
}

Zombie::Zombie(std::string &name): _name(name)
{
	if (name.empty() || name.find_first_not_of(" \t\v\r\n") == name.npos)
	{
		this->_name = "Chowder";
	}
	std::cout << '\t' << this->_name << ":\tZombie created" << std::endl;
}


void Zombie::announce(void)
{
	std::cout << '\t'  << this->_name << ":\tBraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie::~Zombie()
{
	std::cout << '\t'  << this->_name << ":\thas been annihilated."  << std::endl;
}
