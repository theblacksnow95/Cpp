#ifndef SED_HPP
#define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

# define GRN	"\033[0;32m"
# define YLL	"\033[0;33m"
# define RED	"\033[0;31m"
# define RST	"\033[0m"

int	sed(std::string& fileName, std::string s1, std::string s2);

#endif
