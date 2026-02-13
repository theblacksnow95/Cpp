#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	_name = "Flaggy";
	_egPoints = 100;
	_attDamage = 30;
	std::cout << _name << ": FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	if (name.empty())
		this->_name = "Flaggy";
	this->_name = name;
	this->_egPoints = 100;
	this->_attDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

// Copy operator
FragTrap::FragTrap(const FragTrap& other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_egPoints = other._egPoints;
	this->_attDamage = other._attDamage;
}

// copy assignment operator overload
FragTrap& FragTrap::operator=(const FragTrap& other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << _name << ": I frigging love  guys, HIGH FIVES FOR ALL!!" << std::endl;
}
