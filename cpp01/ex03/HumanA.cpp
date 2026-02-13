#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon): _name("Jhonny"), _weapon(weapon)
{
	if (name.empty() || name.find_first_not_of(" \t\v\r\n") == name.npos)
		this->_name = "Jhonny";
	if (weapon.getType().empty())
		this->_weapon = Weapon();
	std::cout << "\t" << this->_name << ": Human A appeard" << std::endl;
}

void	HumanA::attack()
{
	std::cout << "\t" << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout <<  "\t" << "Default human destructor." << std::endl;
}
