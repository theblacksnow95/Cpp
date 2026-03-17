#include "Array.hpp"
#include "Array.tpp"
# include <typeinfo>

template<typename T>
void	print_array(Array<T>& arr, size_t n)
{
	std::cout << GRN << "\t"<< "[" << RST;
	for (size_t i = 0; i < n; i++)
	{
		std::cout << GRN << arr[i] << RST << " ";
	}
	std::cout << GRN << "]" << RST << std::endl;
	std::cout << std::endl;
}

class AClass
{
};

int main()
{
	size_t n = 10;
	Array<int> a;
	Array<double> b(n);
	Array<double> c(n);
	int * num = new int();
	for (size_t i = 0; i < n; i++)
	{
		b[i] = ((i + 1) *3) / 2;
	}
	try
	{
		std::cout << PRL << "Basic test and exception: " << RST << std::endl;	
		std::cout << YLL << "Int test value: " << *num << RST << std::endl;
		std::cout << BLE << "Printing arr b: " << RST << std::endl;
		print_array(b, n);
		std::cout << BLE << "Size of a: " << a.size() << " Size of b: " << b.size() << RST << std::endl;
		std::cout << YLL << "Trying to access a[n]: " << RST << std::endl;
		std::cout << GRN << a[n] << RST << std::endl;
	}
	catch (std::exception& e)
	{
		delete num;
		std::cout << YLL << "Exception detected:" << RST << std::endl;
		std::cout << RED << "\t" << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << PRL << "Copy assignment and copy constructor tests: " << RST << std::endl;
		std::cout << BLE << "Creating variabe (c = b)" << RST << std::endl;
		c = b;
		for (size_t i = 0; i < n; i++)
		{
			c[i] = 100;
		}
		std::cout << YLL << "Modifiying all values in array (c) to 100 ..." << RST << std::endl;
		std::cout << YLL << "Values un c modified: " << RST << std::endl;
		print_array(c, n);
		std::cout << YLL << "Values in b should not change: " << RST << std::endl;
		print_array(b, n);
		std::cout << BLE << "New variable (d) using copy constructor from b:" << RST << std::endl;
		Array<double> d = b;
		print_array(d, n);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try 
	{
		std::cout << PRL << "Test with complex data, T = class: " << RST << std::endl;
		Array<AClass> arr(10);
		std::cout << YLL << "[" << RST ;
		for (size_t i = 0 ; i < 10; i++)
		{
			std::cout << YLL << typeid(arr[i]).name() << RST << " ";
		}
		std::cout << YLL << "]" << RST << std::endl;

		std::cout << BLE << "Size of arr: " << arr.size() << RST << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << YLL << "Exception detected: " << RST << std::endl;
		std::cout << RED << e.what() << RST << std::endl;
	}
	return (0);
}
