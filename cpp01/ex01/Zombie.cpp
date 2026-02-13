#include "Zombie.hpp"

Zombie::Zombie(): _name("Bloaty")
{
	std::cout << GRN <<'\t' << "Zombie created with default constructor" << RST << std::endl;
}

Zombie::Zombie(std::string &name): _name(name)
{
	std::cout << '\t' << this->_name << ":\tZombie created" << std::endl;
}

void Zombie::setName(const std::string& name)
{
	if (name.empty() || name.find_first_not_of(" \t\v\r\n") == name.npos)
	{
		this->_name = "Bloaty";
	}
	this->_name = name;
	std::cout << "\t" << "Name set for zombie: " << name << std::endl; 
}

void Zombie::announce(void)
{
	std::cout << '\t'  << this->_name << ":\tBraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie::~Zombie()
{
	std::cout << '\t'  << this->_name << ":\thas been annihilated."  << std::endl;
}
