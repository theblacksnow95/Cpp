#ifndef RPN_HPP
#define RPN_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include <stack>
# include <cstdlib>

# define ERROPERANDS "Error: incorrect operands"

class RPN
{
	private:
		std::stack<int>	_stack;
		void	fillStack(const std::string& args);
	public:
		RPN();
		RPN(std::string agrs);
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN();
		class excOperands: public std::exception
		{
			const char *what() const throw();
		};
};

#endif
