#include "easyfind.hpp"
# define ERRORFIND	"Value not present in the secuence, try with another."

class EValueNotFound: public std::exception
{
	public:
		const char *what() const throw()
		{
			return ERRORFIND;
		}
};

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
		throw EValueNotFound();
	}
}
