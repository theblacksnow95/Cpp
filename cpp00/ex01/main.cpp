#include "PhoneBook.hpp"
#include <cstdio>
// c++ -Wall -Wextra -Werror -std=c++98 main.cpp PhoneBook.cpp Contact.cpp -o phoneTest

int	main()
{
	std:: string command;
	PhoneBook PhoneBook;
	std::cout << "Enter a command, please: " << std::endl;
	while (std::getline(std::cin,command))
	{
		if (command == "EXIT")
			break;
		if (command == "ADD")
			PhoneBook.Add();
		if (command == "PRINT")
			PhoneBook.printContacts();
		if (command == "SEARCH")
			PhoneBook.Search();
		if (command == "TEST")
			PhoneBook.testADD();
		// else
		// 	std::cout << "You've entered some input:  " <<  command << std::endl;
		std::cout << "Enter a command, please: " << std::endl;
	}
}
