#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

# define GRN	"\033[0;32m"
# define YLL	"\033[0;33m"
# define RED	"\033[0;31m"
# define RST	"\033[0m"

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon();
		Weapon(const std::string& type);
		void				setType(const std::string& type);
		const std::string&	getType();
		~Weapon();
};


#endif
