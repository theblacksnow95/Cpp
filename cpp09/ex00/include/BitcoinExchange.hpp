#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

# include "colors.hpp"
# include <iostream>
# include <string>

class element
{
	private:
		attribute type	_att_name;

	public:
		element();
		element(const element& other);
		element&	operator=(const element& other);
		~element();
};


#endif
