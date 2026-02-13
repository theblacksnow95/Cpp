#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	{
		std::cout << YLL << "Creating Some weapons:" << RST << std::endl;
		Weapon a;
		std::cout << "\t" << "Weapon a before: " << a.getType() << std::endl;
		Weapon b("");
		Weapon c = Weapon("Chainsaw");
		a.setType("Knife");
		std::cout << "\t" << "Weapon a after: " << a.getType() << std::endl;
		std::cout << "\t" << "Weapon b: " << b.getType()  << std::endl;
		std::cout << "\t" << "Weapon c: " << c.getType()  << std::endl;
		
	}
	{
		std::cout << YLL << "Creating Human A:" << RST << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << YLL << "Creating Human B:" << RST << std::endl;
		Weapon club = Weapon(" ");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("Breda-SAFAT machine gun, 7.70×56mmR (known as .303 British), perfect against Communists!");
		jim.attack();
	}
	return (0);
}
