#include "iter.hpp"

// test functions implementation

void	increment(int &val)
{
	val++;
}

template<typename T>
void prints(T &c)
{
	std::cout << GRN << c << RST << std::endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4};
	std::string str[] = {"asd", "ads", "ewf" , "Asd"};
	const int ints[] = {1, 2, 3, 4};
	const char chars[] = {'T', 'g', 'F', 'l'};
	int len = 4;
	std::cout << PRL << "Test with non const ref to arr: " << RST << std::endl;
	std::cout << BLE << "Incrementing array of int..." << RST << std::endl;
	iter(arr, len, increment);
	iter(arr, len, prints<int>);
	std::cout << BLE << "Printing array of strings..." << RST << std::endl;
	iter(str, len, prints<std::string>);
	std::cout << PRL << "Test with const arr references: " << RST << std::endl;
	std::cout << BLE << "Printing a const array of int" << RST << std::endl;
	iter(ints, len, prints<const int>);
	std::cout << BLE<< "Printing a const array of char" << RST << std::endl;
	iter(chars, len, prints<const char>);
	std::cout << YLL << "If we try to modify these values the program will not compile. Because the type must be modifiable" << RST << std::endl;
	// iter(ints, len, increment);
	return (0);
}
