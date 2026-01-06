#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Default constructor called." << std::endl;
}

void Contact::setFname(const std::string& fname)
{
	std::cout << "Set first name." << std::endl;
	_firstName = fname;
}

void Contact::setLname(const std::string& lname)
{
	std::cout << "Set first name." << std::endl;
	_lastName = lname;
}

void Contact::setNickname(const std::string& nick)
{
	std::cout << "Set Nickname." << std::endl;
	_nickName = nick;
}

void Contact::setDarkest(const std::string& secret)
{
	std::cout << "Set secret." << std::endl; 
	_darkestSecret = secret;
}

void Contact::setPhone(const int &phone)
{
	std::cout << "Set Phone number" << std::endl;
	_phone = phone;
}

std::string Contact::getFName() const
{
	return _firstName;
}

std::string Contact::getLName() const
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

int	Contact::getPhone() const
{
	return _phone;
}

Contact::~Contact()
{
	std::cout << "Destructor called." << std::endl;
	
}
