#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"
# define BLUE 9
# define RED 12
# define YLL 14

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		idx;
	public:
		PhoneBook();
		void Add();
		~PhoneBook();
		void printContacts();

}; 

#endif
