#include "FragTrap.hpp"

int	FragTrap::_hitPoints_default = 100;
int	FragTrap::_egPoints_default = 100;
int	FragTrap::_attDamage_default = 30;

FragTrap::FragTrap(): ClapTrap()
{
	_name = "Flaggy";
	_egPoints = _egPoints_default;
	_attDamage = _attDamage_default;
	std::cout << _name << ": FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	if (name.empty())
		_name = "Flaggy";
	_name = name;
	_egPoints = _egPoints_default;
	_attDamage = _attDamage_default;
	std::cout << "FragTrap constructor called" << std::endl;
}

// Copy operator
FragTrap::FragTrap(const FragTrap& other)
{
	_name = other._name;
	_hitPoints_default = other._hitPoints_default;
	_egPoints_default = other._egPoints;
	_attDamage_default = other._attDamage;
}

// copy assignment operator overload
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints_default = other._hitPoints_default;
		_egPoints_default = other._egPoints_default;
		_attDamage_default = other._attDamage_default;
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
