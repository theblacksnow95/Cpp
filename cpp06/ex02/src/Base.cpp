#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{
}
Base*	generate(void)
{
	int	rndIdx = rand() % 3;
	if (rndIdx == 0)
	{
		Base *a = new A();
		return (a);
	}
	if (rndIdx == 1)
	{
		Base *b = new B();
		return (b);
	}
	if (rndIdx == 2)
	{
		Base *c = new C();
		return (c);
	}
	else
		return (0);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << YLL << "Type: A" << RST << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << YLL << "Type: B" << RST << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << YLL << "Type: C" << RST << std::endl;
}

void	identify(Base& p)
{
	try
	{
		Base a = dynamic_cast<A&>(p);
		std::cout << YLL << "Type: A" << RST << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			Base b =  dynamic_cast<B&>(p);
			std::cout << YLL << "Type: B" << RST << std::endl;
		}
		catch (const std::exception& e)
		{
			try
			{
				Base c = dynamic_cast<C&>(p);
				std::cout << YLL << "Type: C" << RST << std::endl;
			}
			catch(const std::exception& e)
			{
			}

		}
	}
}
