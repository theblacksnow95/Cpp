#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << YLL << "First test round" << RST << std::endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		const AAnimal* h = new Cat();
		// AAnimal animal();
		std::cout  << std::endl;
		delete h;
		h = i;
		delete j;//should not create a leak
		// delete i;
		delete h;
		std::cout  << std::endl;
	}
	return (0);
}
