#include "Zombie.hpp"

int	main()
{
	std::cout << YLL << "Initialising default temp zombies" << RST << std::endl;
	Zombie tmpZomb;
	tmpZomb.announce();
	std::cout << YLL << "Random chumps initialising" << RST << std::endl;
	randomChump("Kirk");
	randomChump("Morty");
	randomChump("Pickle Rick");
	std::cout << GRN << "Initialising heap zombies" << RST << std::endl;
	Zombie* allocZomb = newZombie("Elliot");
	Zombie* anotherZomb = newZombie("Theo");
	allocZomb->announce();
	anotherZomb->announce();
	std::cout << RED << "Destroying heap zombies" << RST << std::endl;
	delete allocZomb;
	delete anotherZomb;
	std::cout << RED << "Destroying default zombies" << RST << std::endl;
	return (0);
}
