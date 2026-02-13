#include "Zombie.hpp"

int	main()
{
	std::cout << YLL << "Initialising Zombie array" << RST << std::endl;
	Zombie *arrZomb = zombieHorde(10, "Theo");
	if (arrZomb == NULL)
	{
		std::cout << RED << "Invalid zombie Horde, WTF IS HAPPENING!!!." << RST << std::endl;
		return (1);
	}
	std::cout << YLL << "Array created." << RST << std::endl;
	for (int i = 0; i < 5; i++)
	{
		arrZomb[i].announce();
	}
	std::cout << RED << "Destroying all alloced zombies." << RST << std::endl;
	delete[] arrZomb;
	return (0);
}
