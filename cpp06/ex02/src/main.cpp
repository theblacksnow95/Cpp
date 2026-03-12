#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	srand(time(NULL));
	Base*	a = generate();
	Base &b = *a;
	std::cout << GRN << "Test with pointer to object." << RST << std::endl;
	identify(a);
	std::cout << GRN << "Test with reference to object." << RST << std::endl;
	identify(b);
	delete a;
}
