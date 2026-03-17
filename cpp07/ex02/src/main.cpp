#include "iter.hpp"

void	test(int val)
{
	std::cout << YLL << val << RST << std::endl;
}
void prints(char c)
{
	std::cout << GRN << c << RST << std::endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4};
	char chars[] = {'1', 'g', '5', 'l'};
	int len = 4;

	iter(arr, len, test);
	iter(chars, len, prints);
	return (0);
}
