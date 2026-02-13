#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact()
{
	std::cout << CIAN << "Default Contact constructor called." <<  RST << std::endl;
}

bool Contact::validField(const std::string& string)
{
	if (string.empty())
		return (false);
	if (string.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
		return (false);
	return (true);
}

bool Contact::validChars(const std::string &string)
{
	if (string.empty())
		return (false);
	for (size_t i = 0;i < string.size(); i++)
	{
		if (isspace(string[i]))
			continue;
		if (!isalpha(string[i]))
			return (false);
	}
	return (true);
}

void Contact::setFname(const std::string& fname)
{
	// std::cout << "Set first name." << std::endl;
	_firstName = fname;
}

void Contact::setLname(const std::string& lname)
{
	// std::cout << "Set last name." << std::endl;
	_lastName = lname;
}

void Contact::setNickname(const std::string& nick)
{
	// std::cout << "Set Nickname." << std::endl;
	_nickName = nick;
}

void Contact::setDarkest(const std::string& secret)
{
	// std::cout << "Set secret." << std::endl;
	_darkestSecret = secret;
}

void Contact::setPhone(const std::string &phone)
{
	// std::cout << "Set Phone number" << std::endl;
	_phone = phone;
}

std::string Contact::getFname() const
{
	// std::cout << "First name: ";
	return _firstName;
}

std::string Contact::getLname() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickName;
}


std:: string Contact::getDarkest() const
{
	return _darkestSecret;
}

std::string	Contact::getPhone() const
{
	return _phone;
}

Contact::~Contact()
{
	std::cout << RED << "Destructor Contact called." << RST << std::endl;

}
