#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1 || N >= 200)
		return (NULL);
	Zombie* arrZomb = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		arrZomb[i].setName(name);
	}
	return (arrZomb);
}
