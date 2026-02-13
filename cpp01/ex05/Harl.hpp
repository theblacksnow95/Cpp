#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>
# include <string>

# define GRN	"\033[0;32m"
# define YLL	"\033[0;33m"
# define RED	"\033[0;31m"
# define RST	"\033[0m"


class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	public:
		Harl();
		void	complain( std::string level);
		~Harl();
};

#endif
