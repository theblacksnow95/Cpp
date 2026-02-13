#include "HumanB.hpp"

HumanB::HumanB(): _name("Bob"), _weapon(NULL)
{
	std::cout << "\t" << YLL << "Default HumanB : '" << this->_name << "' constructor." << RST << std::endl; 
}

HumanB::HumanB(const std::string& name): _name("Bob")
{
	if (name.empty() || name.find_first_not_of(" \t\v\r\n") == name.npos)
		this->_name = "Jhonny";
	this->_weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
	if (weapon.getType().empty())
	{
		std::cout << "No valid weapon provided." << std::endl;
		return ;
	}
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (!_weapon)
		std::cout << "\t" << _name << " Cannot attack without a weapon, you dummy!" << std::endl;
	else
		std::cout << "\t" << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "\t" << YLL << "Default HumanB destructor." << RST << std::endl;
}
