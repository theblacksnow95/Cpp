#include "ClapTrap.hpp"


int	main()
{
	ClapTrap	clp;
	ClapTrap	other("Paco");
	
	std::cout << clp.getName() << " Created" << std::endl;
	clp.attack("Paco");
	other.attack("Clappy");
	clp.takeDamage(5);
	other.takeDamage(10);
	other.attack("Clappy");
	clp.attack("Paco");
	clp.beRepaired(10);
	std::cout << "Clappy " << clp.getHits() << " hitpoints left" << std::endl;
	std::cout << "Paco " << other.getHits() << " hitpoints left" << std::endl;
}
