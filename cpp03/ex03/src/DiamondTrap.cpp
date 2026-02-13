#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap::ClapTrap("Putaso_clap_name"), FragTrap("Putaso_clap_name"), ScavTrap("Putaso_clap_name"), _name("Putaso")
{
	std::cout << "Default DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name):ClapTrap::ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), _name(name)
{
	_hitPoints = FragTrap::_hitPoints_default;
	_egPoints = ScavTrap::_egPoints_default;
	_attDamage = FragTrap::_attDamage_default;
	std::cout << "DiamondTrap constructor called " << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap::ClapTrap(other._name + "_clap_name"), FragTrap(other._name + "_clap_name"), ScavTrap(other._name + "_clap_name"), _name(other._name)
{
	_hitPoints = other._hitPoints;
	_egPoints = other._egPoints;
	_attDamage = other._attDamage;
	std::cout << "Copy constructor called." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_egPoints = other._egPoints;
		_attDamage = other._attDamage;
		ClapTrap::_name = other._name + "_clap_name";
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called." << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Who am I, called: " << std::endl;
	std::cout << "\t" << "[Diamond name : " << _name  << "] -- [Clap name : " << ClapTrap::_name << "]" << std::endl;
}
