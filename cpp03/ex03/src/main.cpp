#include "DiamondTrap.hpp"

int	main()
{
	{
		std::cout << YLL << "Test1 : " << RST << std::endl;
		DiamondTrap dia("Jhonny");
		ClapTrap trpb("Helio");
		dia.highFivesGuys();
		dia.attack(trpb.getName());
		dia.guardGate();
		trpb.takeDamage(20);
		trpb.beRepaired(10);
		dia.whoAmI();
	}
	{

		std::cout << std::endl << YLL << "Test2 : " << RST << std::endl;
		DiamondTrap trap("Manu");
		DiamondTrap b(trap);
		DiamondTrap a("Louis");
		a = b;
		std::cout << "values of a: "<< a.getHits() << " -- "<< a.getEnergy() << " -- " << a.getAttack() <<std::endl;
		b.attack("IT");
		std::cout << "Values of b: " << b.getHits() << " -- "<< b.getEnergy() << " -- " << b.getAttack() <<std::endl;
		trap.attack("Zeus");
		trap.beRepaired(100);
		trap.attack("Zeus");
		trap.takeDamage(50);
		trap.attack("Other");
		trap.beRepaired(28);
		trap.guardGate();
		b.whoAmI();
		a.whoAmI();
		a.attack("Zeus");
		a.guardGate();
		a.highFivesGuys();
		std::cout << "values of trap: " << trap.getHits() << " -- "<< trap.getEnergy() << " -- " << trap.getAttack() <<std::endl;
	}
}
