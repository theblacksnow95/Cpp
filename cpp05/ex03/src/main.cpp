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
			Bureaucrat	boss = Bureaucrat("Palpatine", 5);
			form = intern.makeform("pardon request", "Jhonazzi (Totally not a nazi)");
			std::cout << BLE << "\tCreated form name: " << form->getName() << RST << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
		catch (std::exception & e)
		{
			delete form;
			std::cout << YLL << "\t\tException detected:" << RST << std::endl;
			std::cerr << RED << e.what() << RST << std::endl;
		}
		try
		{
			form = NULL;
			std::cout << std::endl << PRL << "Test 2: Intern form WRONG creation test." << RST << std::endl;
			Intern	intern = Intern();
			Bureaucrat	boss = Bureaucrat("Palpatine", 5);
			form = intern.makeform("democracy request", "Russia");
			std::cout << BLE << "\tCreated form name: " << form->getName() << RST << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;

		}
		catch(const std::exception& e)
		{
			delete form;
			std::cout << YLL << "\t\tException detected:" << RST << std::endl;
			std::cerr << RED << e.what() << RST << std::endl;
		}

	}
}
