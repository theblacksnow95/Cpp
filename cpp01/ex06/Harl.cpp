# include "Harl.hpp"

Harl::Harl()
{
}
void	Harl::debug(void)
{
	std::cout  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 5;
	for (int j = 0; j < 4; j++)
	{
		if (level == arr[j])
		{
			i = j;
			break ;
		}
	}
	switch (i) 
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return ; 
	}
}

Harl::~Harl()
{
}
