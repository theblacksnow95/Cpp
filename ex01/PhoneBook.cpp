#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): idx(0), ok(false)
{
	std::cout << GRN <<"Default PHONEBOOK constructor called."<< RST << std::endl << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << YLL << "Destructor PHONEBOOK called." << RST << std::endl;
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
	do
	{
		std::cout << "First name: " << std::endl;
		getline(std::cin, input);
		contacts[i].setFname(input);
	}
	while (!contacts->validField(input));
	do
	{
		std::cout << "Last name: " << std::endl;
		getline(std::cin, input);
		contacts[i].setLname(input);
	}
	while (!contacts->validField(input));
	do
	{
	std::cout << "Nickname: " << std::endl;
	getline(std::cin, input);
	contacts[i].setNickname(input);
	}
	while (!contacts->validField(input));
	do
	{
	std::cout << "Phone number: " << std::endl;
	getline(std::cin, input);
	contacts[i].setPhone(input);
	}
	while ((!contacts->validField(input) || input.find_first_not_of("+0987654321") != input.npos)
			|| !(input.length() >= 9 && input.length() <= 11));
	do
	{
	std::cout << "Darkest secret: " << std::endl;
	getline(std::cin, input);
	contacts[i].setDarkest(input);
	}
	while (!contacts->validField(input));
	std::cout << "contact --> [" << contacts[i].getFname() << "] added to contacts array." << std::endl;
	std::cout << "Index position: [" << (idx + 1) % 9 << "]" << std::endl;
	idx++;
}

void	PhoneBook::Search()
{
	int 		i = 0;
	std::string	s;

	std::cout << CIAN << "\t" << "|   Index  |First Name| Last Name| Nickname |" << RST << std::endl;
	while (i < 8 && !contacts[i].getFname().empty())
	{

		std::cout << "\t";
		std::cout << std::right << "|     " << i << "    |";
		if (contacts[i].getFname().size() > 10)
		{
			s = contacts[i].getFname();
		std::cout << std::right << s.substr(0, 9) << '.'<< "|";
		}
		else
		{
			s = contacts[i].getFname();
			int len = s.size();
			len = 10 - len;
			if (len < 0)
				len = 0;
			std::cout << std::right <<  s << std::string(len, ' ') << "|";
		}
		if (contacts[i].getLname().size() > 10)
		{
			s = contacts[i].getLname();
		std::cout << std::right << s.substr(0, 9) << '.' << "|";
		}
		else
		{
			s = contacts[i].getLname();
			int	len = s.size();
			len = 10 - len;
			if (len < 0)
				len = 0;
			std::cout << std::right << s << std::string(len, ' ') << "|";
		}
		if (contacts[i].getNickname().size() > 10)
		{
			s = contacts[i].getNickname();
			std::cout << std::right << s.substr(0, 9) << '.' << "|";
		}
		else
		{
			s = contacts[i].getNickname();
			int len = s.size();
			len = 10 - len;
			if (len < 0)
				len = 0;
			std::cout << std::right << s << std::string(len, ' ') << "|";
		}
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
}

void PhoneBook::printContacts()
{
	std::cout << "Print contact list names." << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "First name: " << contacts[i].getFname() << std::endl;
	}
}

void PhoneBook::testADD()
{
	std::string Farr[] = {"La Jessy", "Luca", "MANOLO", "Giuseppe", "VErgoglio", "Amparinos", "Maria del Carmen", "Andreita"};
	std::string Larr[] = {"Chungaa", "Manolo", "Estanco", "De las flores", "   Fetucini", "Cuesta mogollon", "Latios", "Matamoros"};
	std::string Narr[] = {"Bakalaera", "El Pepe", "Facha", "Fuckero", "La salsa", "Mamadica", "TDS pts", "El diablo",};
	std::string Parr[] = {"123123123","123123123","123123123","123123123","123123123","123123123","123123123","123123123"};
	std::string Darr[] = {"Se droga", "Es gay", "Mas gay aun", "Un puto", "la chupa", "Le mola la farlopa", "Es swinger", "To racista"};

	std::cout << YLL << "Loading contacts to list" << RST << std::endl;
	for (int i = 0; i < 8; i++)
	{

		contacts[i].setFname(Farr[i]);
		contacts[i].setLname(Larr[i]);
		contacts[i].setNickname(Narr[i]);
		contacts[i].setPhone(Parr[i]);
		contacts[i].setDarkest(Darr[i]);
	}
	std::cout << GRN << "Loading successful." << RST << std::endl;
}
