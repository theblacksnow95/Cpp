#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_name = "Scavvy";
	std::cout << "ScavTrap Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	if (name.empty())
		this->_name = "Scavvy";
	std::cout << "ScavTrap constructor called " << _name << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_egPoints = other._egPoints;
	this->_attDamage = other._attDamage;

}

// Copy assignment operator overload
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_egPoints = other._egPoints;
		this->_attDamage = other._attDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_egPoints <= 0 )
		std::cout << _name << ": No energy available, cannot attack" << std::endl;
	if (this->_hitPoints <= 0)
		std::cout << _name << ": No hit points available, cannot attack" << std::endl;
	else
	{
		std::cout << this->getName() << "ScavTrap attacks " << target << ", causing " << this->_attDamage << " points of damage!" << std::endl;
		this->_egPoints--;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << this->_name << " has changed to Gate keeper mode." << std::endl;
}
