#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"
# define CIAN	"\033[36m"
# define RED	"\033[31m"
# define YLL	"\033[33m"
# define GRN	"\033[32m"
# define RST	"\033[0m"



class PhoneBook
{
	private:
		Contact	contacts[8];
		int		idx;
		bool	ok;
	public:
		PhoneBook();
		void Add();
		void Search();
		~PhoneBook();
		void printContacts();
		void testADD();

};

#endif
