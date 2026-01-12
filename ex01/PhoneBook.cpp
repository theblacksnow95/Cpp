#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook(): idx(0)
{
	std::cout << GRN <<"Default PHONEBOOK constructor called."<< RST << std::endl << std::endl;
}



std::string	cleanInput(const std::string &input)
{
	std::string tmp = input;
	std::string res;
	std::string whiteSpaces = " \t\v\r\n";
	bool inspace = false;
	for (size_t i = 0; i < tmp.length() -1; i ++)
		if (std::isspace(tmp[i]))
			tmp[i] = ' ';
	for (size_t i = 0; i < tmp.length() ; i++)
	{
		if (std::isspace(tmp[i]))
		{
			if (!inspace)
			{
				res += ' ';
				inspace = true;
			}
		}
		else
		{
			res += input[i];
			inspace = false;
		}
	}
	std::size_t start = res.find_first_not_of(whiteSpaces);
	std::size_t end = res.find_last_not_of(whiteSpaces);
	if (start == end)
		return (res);

	std::cout << "END: " << end << std::endl;
	std::cout << "START: " << start << std::endl;
	std::cout << "-->" << res << std::endl;

	return (res.substr(start, end - start + 1));
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

			if (!getline(std::cin, input))
			{
				std::cout << "Exiting from EOF." << std::endl;
				return;
			}
			if (input.empty())
				continue;
			std::string res(cleanInput(input));
			contacts[i].setFname(res);
	}
	while (!contacts->validField(input) || !contacts->validChars(input));
	do
	{
		std::cout << "Last name: " << std::endl;
		if (!getline(std::cin, input))
		{
			std::cout << "Exiting from EOF." << std::endl;
			return;
		}
		if (input.empty())
			continue;
		std::string res(cleanInput(input));
		contacts[i].setLname(res);
	}
	while (!contacts->validField(input) || !contacts->validChars(input));
	do
	{
		std::cout << "Nickname: " << std::endl;
		if (!getline(std::cin, input))
		{
			std::cout << "Exiting from EOF." << std::endl;
			return;
		}
		if (input.empty())
			continue;
		std::string res(cleanInput(input));
		contacts[i].setNickname(res);
	}
	while (!contacts->validField(input) || !contacts->validChars(input));
	do
	{
		std::cout << "Phone number: " << std::endl;

		if (!getline(std::cin, input))
		{
				std::cout << "Exiting from EOF phone." << std::endl;
				return;
		}
		if (input.empty())
			continue;
		contacts[i].setPhone(input);
	}
	while ((!contacts->validField(input) || input.find_first_not_of("+0987654321") != input.npos)
			|| !(input.length() >= 9 && input.length() <= 11));
	do
	{
		std::cout << "Darkest secret: " << std::endl;
		if (!getline(std::cin, input))
		{
			std::cout << "Exiting from EOF." << std::endl;
			return;
		}
		if (input.empty())
			continue;
		std::string res(cleanInput(input));
		contacts[i].setDarkest(res);
	}
	while (!contacts->validField(input) || !contacts->validChars(input));
	std::cout << "contact --> [" << YLL << contacts[i].getFname() << RST << \
	"] added to contacts array." << std::endl;
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
		std::cout << std::right << CIAN << "|     " << RED << i + 1 << CIAN << "    |" << RST;
		if (contacts[i].getFname().size() > 10)
		{
			s = contacts[i].getFname();
			std::cout << YLL << std::right << s.substr(0, 9) << '.' << RST;
			std::cout << CIAN << "|" << RST;

		}
		else
		{
			s = contacts[i].getFname();
			int len = s.size();
			len = 10 - len;
			if (len < 0)
				len = 0;
			std::cout << YLL << std::right <<  s << std::string(len, ' ') << RST;
			std::cout << CIAN << "|" << RST;

		}
		if (contacts[i].getLname().size() > 10)
		{
			s = contacts[i].getLname();
			std::cout << YLL << std::right << s.substr(0, 9) << '.' << RST;
			std::cout << CIAN << "|" << RST;
		}
		else
		{
			s = contacts[i].getLname();
			int	len = s.size();
			len = 10 - len;
			if (len < 0)
				len = 0;
			std::cout << YLL << std::right << s << std::string(len, ' ') << RST;
			std::cout << CIAN << "|" << RST;
		}
		if (contacts[i].getNickname().size() > 10)
		{
			s = contacts[i].getNickname();
			std::cout << YLL << std::right << s.substr(0, 9) << RST << '.';
			std::cout << CIAN << '|' << RST;
		}
		else
		{
			s = contacts[i].getNickname();
			int len = s.size();
			len = 10 - len;
			if (len < 0)
				len = 0;
			std::cout << YLL << std::right << s << std::string(len, ' ') << RST;
			std::cout << CIAN << "|" << RST;

		}
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	selectContact();
}

void PhoneBook::selectContact()
{
	std::string	input;
	int			i;
	std::cout << "Select a contact to display [1 - 8]: " << std::endl;
	while (true)
	{
		if (!getline(std::cin,input) )
		{
			std::cout << "Exiting with EOF." << std::endl;
			return ;
		}
		if (input.size() != 1 || input.find_first_not_of("12345678") != input.npos)
		{
			std::cout << RED << "Invalid index" << RST << std::endl;
			return ;
		}
		i = input[0] - '0' - 1;
		if (contacts[i].getFname().empty())
		{
			std::cout << RED << "Invalid index" << RST << std::endl;
			return ;
		}
		std::cout << std::string(100, '-') << std:: endl;
		std::cout << "\t" << "First name:\t" << contacts[i].getFname() << std::endl;
		std::cout << "\t" << "Last name:\t" << contacts[i].getLname() << std::endl;
		std::cout << "\t" << "Nickname:\t" << contacts[i].getNickname() << std::endl;
		std::cout << "\t" << "Phone Number:\t" << contacts[i].getPhone() << std::endl;
		std::cout << "\t" << "Darkest secret:\t" << contacts[i].getDarkest() << std::endl;
		std::cout  << std::string(100, '-') << std:: endl;
		return;
	}
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
	std::string Larr[] = {"Chungaa", "Manolo", "Estanco", "De las flores", "Fetucini", "Cuesta mogollon", "Latios", "Matamoros"};
	std::string Narr[] = {"Bakalaera", "El Pepe", "Facha", "Fuckero", "La salsa", "Mamadica", "TDS TDS", "El diablo",};
	std::string Parr[] = {"123123123","567238731","876456231","098567432","123123123","234345321","098765678","098124326"};
	std::string Darr[] = {"Se droga", "Smash", "Elliot puto", "NErd", "la chupa", "Le mola farlopa", "Es swinger", "Fachirulo"};

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
