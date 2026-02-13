#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << YLL << "First test round" << RST << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		const Animal* h = new Cat();
		std::cout  << std::endl;
		delete h;
		h = i;
		delete j;//should not create a leak
		// delete i;
		delete h;
		std::cout  << std::endl;
	}
	{
		std::cout  << std::endl << YLL << "Second test round" << RST << std::endl;
		std::cout << '\t' << "Animals array created: N = 6" << std::endl;
		Animal *arr[N_ARR];
		std::cout  << std::endl;
		std::cout << '\t' << YLL << "Populating array with Cats and Dogs: " << RST << std::endl;
		for (int i = 0; i < N_ARR; i++)
		{
			if (i < N_ARR/2)
				arr[i] = new Dog();
			if (i >= N_ARR/2)
				arr[i] = new Cat();
		}
		std::cout  << std::endl;
		std::cout << '\t' << YLL << "Deleting all the Animals in the array" << RST << std::endl;
		for (size_t i = 0; i < N_ARR; i++)
			delete arr[i];
	}
	{
		std::cout  << std::endl << YLL << "Third test round" << RST << std::endl;
		std::cout << '\t' << "Deep copy check: " << std::endl;
		Cat a;
		Cat b = a;
		std::cout << '\t' << "cat a name: " << a.getName() << std::endl;
		std::cout << '\t' << "cat b name: " << b.getName() << std::endl;
		std::cout << '\t' << "<< b has been set equal to a. >>" << std::endl;
		a.setName("Another cat");
		std::cout << '\t' << "<< cat a name has been changed. >>" << std::endl;
		std::cout << '\t' << "cat a Name: " << a.getName() << std::endl;
		std::cout << '\t' << "cat b Name: " << b.getName() << std::endl;
	}
	return (0);
}
