#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		std::cout << YLL << "First test round: " << RST << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\t" << j->getType() << " " << std::endl;
		std::cout << "\t" << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete i;
		delete j;
		delete meta;
	}
	{
		std::cout << std::endl << YLL << "second test round: " << RST <<std::endl;
		const WrongAnimal*	meta = new WrongAnimal();
		const WrongAnimal*	i = new WrongCat();
		const Animal*	j = new Cat();
		const Animal*	c;
		c = j;
		std::cout << "\t" << i->getType() << " " << std::endl;
		std::cout << "\t" << j->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		c->makeSound();
		delete i;
		delete c;
		delete meta;
		return (0);
	}
}
