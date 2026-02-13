#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	{
		std::cout << YLL << "Claptrap tests: " << RST << std::endl << std::endl;
		ClapTrap	clp;
		ClapTrap	other("paco");
		
		std::cout << clp.getName() << " Created" << std::endl;
		clp.attack("Paco");
		other.attack("Clappy");
		clp.takeDamage(5);
		other.takeDamage(5);
		clp.attack("Paco");
		clp.beRepaired(10);
		std::cout << clp.getName() << " has " << clp.getHits() << " hitpoints left" << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << YLL << "ScavTrap test: " << RST << std::endl << std::endl;
		ScavTrap scav("Norm");
		ScavTrap a;
		std::cout << GRN << a.getName() << " has: " << a.getHits() << " hit points, " << a.getEnergy() << " energy points, and " << a.getAttack() << " attack damage." << RST << std::endl;
		scav.attack("Paquito");
		scav.guardGate();
		a.attack("Norm");
		a.takeDamage(20);
		a.beRepaired(2);
		a.guardGate();
		std::cout << GRN << a.getName() << " has: " << a.getHits() << " hit points, " << a.getEnergy() << " energy points, and " << a.getAttack() << " attack damage." << RST << std::endl;
	}
}
