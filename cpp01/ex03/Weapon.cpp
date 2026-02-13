#include "Weapon.hpp"

Weapon::Weapon(): _type("Unknown")
{
	std::cout << "\t" << GRN << "Default contructor Weapon" << RST << std::endl;
}

Weapon::Weapon(const std::string& type): _type(type)
{
	if (type.empty() || type.find_first_not_of(" \t\v\r\n") == type.npos)
	{
		this->_type = "<3 Depression <3";
	}
}
void	Weapon::setType(const std::string& type)
{
	if (type.empty() || type.find_first_not_of(" \t\v\r\n") == type.npos)
	{
		this->_type = "<3 Depression <3";
	}
	this->_type = type;
}

const std::string& Weapon::getType()
{
	return (this->_type);
}

Weapon::~Weapon()
{
	std::cout << "\t" << RED << "Default weapon destructor" << RST << std::endl;
}
