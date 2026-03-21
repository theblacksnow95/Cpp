#ifndef SPAN_HPP
#define SPAN_HPP

# include "colors.hpp"
# include <iostream>
# include <string>

class Span
{
    private:
        long int	nums;


    public:
        Span();
        Span(const Span& other);
        Span&	operator=(const Span& other);
        ~Span();
};


#endif
