#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkestSecret;
		std::string	_phone;
	public:
		// Constructor
		Contact();
		// Setters and getters
		void		setFname(const std::string& fname);
		void		setLname(const std::string& lname);
		void		setNickname(const std::string& nick);
		void		setDarkest(const std::string& secret);
		void		setPhone (const std::string& phone);
		std::string	getFname() const;
		std::string	getLname() const;
		std::string	getNickname() const;
		std::string	getDarkest() const;
		std::string	getPhone() const;
		bool		validField(const std::string &string);
		// Destructor
		~Contact();
};







#endif
