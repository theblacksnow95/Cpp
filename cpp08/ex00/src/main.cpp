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
	
	init_conts(v);
	init_conts(d);
	init_conts(l);
	int val = 6;
	
	easyfind<std::vector<int> >(v, val);
	easyfind<std::deque<int> >(d, val);
	easyfind<std::list<int> >(l, val);
	increase_vals(v);
	increase_vals(d);
	increase_vals(l);
	int tgt = 34;
	easyfind<std::vector<int> >(v, tgt);
	easyfind<std::deque<int> >(d, tgt);
	easyfind<std::list<int> >(l, tgt);
	return (0);
}
