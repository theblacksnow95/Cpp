#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): idx(0) 
{ 
	std::cout << "Default constructor called." << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Destructor PhoneBook called." << std::endl;
}

void PhoneBook::Add()
{
	int	i = 0;
	if (idx >= 8)
	{
		i = idx % 8;
	}
	else 
		i = idx;
	std::string input;
	std::cout << "First name: " << std::endl;
	getline(std::cin, input);
	contacts[i].setFname(input);
	std::cout << "Last name: " << std::endl;
	getline(std::cin, input);
	contacts[i].setLname(input);
	std::cout << "Nickname: " << std::endl;
	getline(std::cin, input);
	contacts[i].setNickname(input);
	std::cout << "Phone number: " << std::endl;
	getline(std::cin, input);
	contacts[i].setPhone(input);
	std::cout << "Darkest secret: " << std::endl;
	getline(std::cin, input);
	contacts[i].setDarkest(input);
	idx++;
}

void PhoneBook::printContacts()
{
	std::cout << "Print contact list names." << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << contacts[i].getFName() << std::endl;
	}
}
