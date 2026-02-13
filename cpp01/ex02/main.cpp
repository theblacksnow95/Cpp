#include <iostream>
#include <string>

int	main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *p = &s;
	std::string &r = s;

	std::cout << "Address of <s> string: " << &s << std::endl;
	std::cout << "Address of <p> string: " << p << std::endl;
	std::cout << "Address of <r> string: " << &r << std::endl << std::endl;
	std::cout << "Value pointed by the <s> variable: " << s << std::endl;
	std::cout << "Value pointed by the <p> variable: " << *p << std::endl;
	std::cout << "Value pointed by the <r> variable: " << r << std::endl;
}
