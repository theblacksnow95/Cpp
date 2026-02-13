#include "ScavTrap.hpp"
int	ScavTrap::_hitPoints_default = 100;
int	ScavTrap::_egPoints_default = 50;
int	ScavTrap::_attDamage_default = 20;

ScavTrap::ScavTrap(): ClapTrap()
{
	_name = "Scavvy";
	_egPoints = _egPoints_default;
	_attDamage = _attDamage_default;
	std::cout << "ScavTrap Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	if (name.empty())
		this->_name = "Scavvy";	
	_egPoints = _egPoints_default;
	_attDamage = _attDamage_default;
	std::cout << "ScavTrap constructor called " << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
{
	this->_name = other._name;
	this->_hitPoints_default = other._hitPoints_default;
	this->_egPoints_default = other._egPoints_default;
	this->_attDamage_default = other._attDamage_default;
}

// Copy assignment operator overload
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints_default = other._hitPoints_default;
		this->_egPoints_default = other._egPoints_default;
		this->_attDamage_default = other._attDamage_default;
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
		std::cout << this->getName() << " Scavtrap attacks " << target << ", causing " << this->_attDamage << " points of damage!" << std::endl;
		this->_egPoints--;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << this->_name << " has changed to Gate keeper mode." << std::endl;
}
