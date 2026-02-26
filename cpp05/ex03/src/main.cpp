#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main ()
{
	{
		try
		{
			std::cout << std::endl << PRL << "Test 1: Shrubbery form test." << RST << std::endl;
			Bureaucrat	bur = Bureaucrat("Paul", 100);
			ShrubberyCreationForm	shrubbery = ShrubberyCreationForm("Backdoor garden");
			std::cout << BLE << bur << RST << std::endl;
			std::cout << YLL << "\tTrying to sign form" << RST << std::endl;
			bur.signForm(shrubbery);
			std::cout << BLE << shrubbery << RST << std::endl;
			bur.executeForm(shrubbery);
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\t\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}
		try
		{
			std::cout << std::endl << PRL << "Test 2: Robotomize test." << RST << std::endl;
			srand( time( NULL ) );
			Bureaucrat	Buro = Bureaucrat("Fidel", 45);
			Bureaucrat	func = Bureaucrat("Marcus", 100);
			RobotomyRequestForm	Robotomy = RobotomyRequestForm("Theo");
			RobotomyRequestForm	Robotomy2 = RobotomyRequestForm("Fidel");
			Buro.signForm(Robotomy);
			Buro.executeForm(Robotomy);
			func.signForm(Robotomy2);
			func.executeForm(Robotomy2);
		}
		catch(const std::exception& e)
		{
			std::cout << YLL << "\t\tException detected:" << RST << std::endl;
			std::cerr << RED << e.what() << '\n';
		}
		try 
		{
			std::cout << std::endl << PRL << "Test 3: Presidential pardon test." << RST << std::endl;
			PresidentialPardonForm	form1 = PresidentialPardonForm("Alt right Nostalgic 500");
			Bureaucrat	Bastard = Bureaucrat("Lider", 100);
			Bastard.executeForm(form1);
			Bastard.signForm(form1);
		}
		catch (std::exception & e)
		{
			std::cout << YLL << "\t\tException detected:" << RST << std::endl;
			std::cout << RED << e.what() << RST << std::endl;
		}
	}
}
