#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie*	allocZombie = new Zombie(name);
	return (allocZombie);
}
