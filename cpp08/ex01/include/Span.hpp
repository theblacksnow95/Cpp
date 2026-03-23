#ifndef SPAN_HPP
#define SPAN_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <climits>

# define EXCOOB		"Error: cannot add more values to the sequence."
# define ERRSPAN	"Error: not enough values to calculate the span distance."
# define EXCMAXN	"Error: cannot create a class with more space than INT_MAX value."

class Span
{
	private:
		std::vector<int>	_arr;
		unsigned int		_N;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		unsigned int getUsed() const;
		unsigned int getSize() const;

		void addNumber(int num);

		unsigned int shortestSpan();
		unsigned int longestSpan();
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class OOBouds: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NonSpan: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class MaxNExc: public std::exception
		{
			public:
				const char* what() const throw();
		};
		~Span();
};

std::ostream&	operator<<(std::ostream& o, const Span& a);

#endif
