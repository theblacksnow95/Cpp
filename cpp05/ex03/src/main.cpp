#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main ()
{
	{
		AForm*	form;
		srand (time(NULL));
		try
		{
			std::cout << std::endl << PRL << "Test 1: Intern form creation test." << RST << std::endl;
			Intern	intern = Intern();
			Bureaucrat	boss = Bureaucrat("Bossy", 10);
			form = intern.makeform("robotomy request", "Jhonazzi (Totally not a nazi)");
			std::cout << BLE << "\tCreated form name: " << form->getName() << RST << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
		catch (std::exception & e)
		{
			delete form;
			std::cout << YLL << "\t\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}
	}
}
