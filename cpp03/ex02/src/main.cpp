#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	{
		std::cout << YLL << "Test1 :" << RST << std::endl;
		FragTrap obj("Biggus");
		FragTrap ob2("Dickus");
		obj.attack("Dickus");
		ob2.takeDamage(30);
		obj.highFivesGuys();
	}
	{
		std::cout << std::endl << YLL << "Another test: " << RST << std::endl;
		FragTrap frg;
		FragTrap trp("Flacidus");
		frg.attack("Hardius");
		trp.beRepaired(20);
		trp.takeDamage(50);
		frg.highFivesGuys();
		trp.highFivesGuys();
	}
}
