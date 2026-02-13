#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(): _name("Clappy"), _hitPoints(10), _egPoints(10), _attDamage(0)
{
	std::cout << "Default constructor called." << std::endl;
}
// Name constructor
ClapTrap::ClapTrap(const std::string& name): _hitPoints(10), _egPoints(10),_attDamage(0) 
{
	std::cout << "Constructor called." << std::endl;
	if(name.empty())
		_name = "Clappy";
	this->_name = name;
}

// Copy contructor
ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hitPoints(other._hitPoints), _egPoints(other._egPoints), _attDamage(other._attDamage)
{
	std::cout << this->_name << ": Copy constructor called." << std::endl;
}
// Copy assignment operator overload
ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_egPoints = other._egPoints;
		_attDamage = other._attDamage;
	}
	return (*this);
}

const std::string& ClapTrap::getName()
{
	return (this->_name);
}

const int&	ClapTrap::getHits()
{
	return (this->_hitPoints);
}

const int&	ClapTrap::getEnergy()
{
	return (this->_egPoints);
}

const int&	ClapTrap::getAttack()
{
	return (this->_attDamage);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_egPoints <= 0 )
		std::cout << _name << ": No energy available, cannot attack" << std::endl;
	if (this->_hitPoints <= 0)
		std::cout << _name << ": No hit points available, cannot attack" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing 1 points of damage!" << std::endl;
		this->_egPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints = this->_hitPoints - amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
	}
	else
		std::cout << "Hey!, its already dead, you are a monster F*** YOU." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_egPoints <= 0)
		std::cout << "No energy left, cannot repair itself." << std::endl;
	if (this->_hitPoints <= 0)
		std::cout << "No hit points left, cannot repair itself." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->getName() << " has repaired " << amount << " hit points" << std::endl;
		if (_hitPoints + amount > 10)
			_hitPoints = 10;
		else
			this->_hitPoints = this->_hitPoints + amount;
		this->_egPoints--;
	}
}
