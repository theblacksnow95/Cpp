#ifndef BASE_HPP
#define BASE_HPP

# include "colors.hpp"
# include <iostream>
# include <string>

class Base
{
	private:
		Base();
	public:
		virtual ~Base();
		Base*	generate(void);
};


#endif
