#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{

}

Base::~Base()
{
}
Base*	Base::generate(void)
{
	int	rndIdx = rand() % 3;
	if (rndIdx == 0)
	{
		Base * a = A();
		return 
	}
}
