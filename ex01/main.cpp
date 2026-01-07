#include "PhoneBook.hpp"

int	main()
{
	std:: string command;
	std::cout << "Enter some command, please: " << std::endl;
	while (std::getline(std::cin,command))
	{
		if (command == "EXIT")
			break;
		else 
			std::cout << "You've entered some input:  " <<  command << std::endl;
		std::cout << "Enter some command, please: " << std::endl;
	}

}
