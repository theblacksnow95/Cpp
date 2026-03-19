#include "easyfind.hpp"

template <typename T>
void	easyfind(const T &cont, int target)
{
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), target);
	if (it != cont.end())
	{
		int	pos = std::distance(cont.begin(), it);
		std::cout << YLL << "Found value: " << target << " in position: " << pos << RST << std::endl;
	}
	else
	{
		EValueNotFound a = 0;
	}
}
