#include "easyfind.hpp"

template<typename T>
void	init_conts(T &container)
{
	container.push_back(3);
	container.push_back(1);
	container.push_back(6);
	container.push_back(9);	
}

template<typename T>
void	increase_vals(T &cont)
{
	cont.push_back(90);
	cont.push_back(50);
	cont.push_back(34);
	cont.push_back(82);
}

int main()
{
	std::vector<int>	v;
	std::deque<int>		d;
	std::list<int>		l;
	try 
	{
		std::cout << PRL << "Test with vector: " << RST << std::endl;
		init_conts(v);
		int val = 6;
		easyfind<std::vector<int> >(v, val);
		increase_vals(v);
		easyfind<std::vector<int> >(v, val);
	}
	catch (std::exception& e)
	{
		std::cout << YLL << "Exception detected: " << RST << std::endl;
		std::cout << RED << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << PRL << "Test with vector: " << RST << std::endl;
		init_conts(v);
		int val = 6;
		easyfind<std::vector<int> >(v, val);
		increase_vals(v);
		easyfind<std::vector<int> >(v, tgt);

	}
	catch (std::exception& e)
	{
		std::cout << YLL << "Exception detected: " << RST << std::endl;
		std::cout << RED << e.what() << RST << std::endl;
	}
	init_conts(d);
	init_conts(l);
	
	easyfind<std::deque<int> >(d, val);
	easyfind<std::list<int> >(l, val);
	increase_vals(d);
	increase_vals(l);
	int tgt = 34;
	easyfind<std::deque<int> >(d, tgt);
	easyfind<std::list<int> >(l, tgt);
	return (0);
}
