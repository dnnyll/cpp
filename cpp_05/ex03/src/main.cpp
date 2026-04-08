/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:49:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/31 12:58:56 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"
#include <iostream>
#include <string>

int	main()
{
	std::cout << "\n==========\tPresidential Test\t==========\n" << std::endl;
	{
		try
		{
			Intern		intern0;
			Bureaucrat	b0("Coy", 1);

			AForm*	form = intern0.makeForm("PresidentialPardonForm", "Coy");

			b0.signForm(*form);
			b0.executeForm(*form);

			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	
	std::cout << "\n==========\tRobotomy Test\t==========\n" << std::endl;
	{
		try
		{
			Intern		intern0;
			Bureaucrat	b0("Coy", 1);

			AForm*	form = intern0.makeForm("RobotomyRequestForm", "Coy");

			b0.signForm(*form);
			b0.executeForm(*form);

			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	
	std::cout << "\n==========\tShrubbery Test\t==========\n" << std::endl;
	{
		try
		{
			Intern		intern0;
			Bureaucrat	b0("Coy", 1);

			AForm*	form = intern0.makeForm("ShrubberyCreationForm", "Coy");

			b0.signForm(*form);
			b0.executeForm(*form);
			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	
	std::cout << "\n==========\tWrong Test\t==========\n" << std::endl;
	{
		Intern		intern0;
		Bureaucrat	b0("Coy", 1);

		try
		{
			AForm*	form = intern0.makeForm("WrongForm", "Coy");

			b0.signForm(*form);
			b0.executeForm(*form);

			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n==========\tLowGrade execution Test\t==========\n" << std::endl;
	{
		try
		{
			Intern		intern;
			Bureaucrat	b0("Coy", 150);

			AForm*	form = intern.makeForm("PresidentialPardonForm", "target");

			b0.signForm(*form);
			b0.executeForm(*form);

			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	return (0);
}