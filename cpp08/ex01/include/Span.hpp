#ifndef SPAN_HPP
#define SPAN_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

# define EXCOOB	"Error: cannot add a more values to the sequence."

class Span
{
	private:
		std::vector<int>	_arr;
		unsigned int		_N;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		unsigned int getSize() const;
		void addNumber(int num);

		class OOBouds: public std::exception
		{
			public:
				const char* what() const throw();
		};
		~Span();
};

std::ostream&	operator<<(std::ostream& o, const Span& a);

#endif
