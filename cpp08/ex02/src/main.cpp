#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> test;
	{
		std::cout << PRL << "Test from the subject: " << RST << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << "\t" << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "\t" << "Poped one out" << std::endl;
		std::cout << "\t" << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "\t" << "Printing all" << std::endl;
		while (it != ite)
		{
		std::cout << "\t" << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << PRL << "Test with list: " << RST << std::endl;
		test.push_back(5);
		test.push_back(17);
		std::cout << "\t" << "top: " << test.back() << std::endl;
		test.pop_back();
		std::cout << "\t" << "Poped one out" << std::endl;
		std::cout << "\t" << "size: " << test.size() << std::endl;
		test.push_back(3);
		test.push_back(5);
		test.push_back(737);
		test.push_back(0);
		std::list<int>::iterator it = test.begin();
		std::list<int>::iterator ite = test.end();
		++it;
		--it;
		std::cout << "\t" << "Printing all:" << std::endl;
		while (it != ite)
		{
		std::cout << "\t" << *it << std::endl;
		++it;
		}
	}
	{
		std::cout << PRL << "Another test: " << RST << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
				std::cout << "\t" << "Printing all:" << std::endl;
		while (rit != rite)
		{
			std::cout << "\t" << *rit << std::endl;
		++rit;
		}
	}
	return 0;
}

